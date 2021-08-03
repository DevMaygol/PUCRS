/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdio.h"
#include "stdlib.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define cursor_apagado	0x0c
#define cursor_aceso	0x0e
#define cursor_piscando	0x0f

#define en_0	GPIOA -> BRR  = 1<<0
#define en_1	GPIOA -> BSRR = 1<<0
#define rs_0	GPIOA -> BRR  = 1<<1
#define rs_1	GPIOA -> BSRR = 1<<1

#define d7_0	GPIOA -> BRR  = 1 << 5
#define d7_1	GPIOA -> BSRR = 1 << 5
#define d6_0	GPIOA -> BRR  = 1 << 4
#define d6_1	GPIOA -> BSRR = 1 << 4
#define d5_0	GPIOA -> BRR  = 1 << 3
#define d5_1	GPIOA -> BSRR = 1 << 3
#define d4_0	GPIOA -> BRR  = 1 << 2
#define d4_1	GPIOA -> BSRR = 1 << 2
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

void lcd_wrcom(uint8_t com);
void lcd_wrchar(char ch);
void lcd_init(uint8_t cursor);
void lcd_clear (void);
void lcd_goto(uint8_t x, uint8_t y);
void lcd_wrstr(char *str);
void lcd_default(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  char teclado[4][4] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'c','0','=','+'}};
  char tecla_pres = '$';
  char num_calc[5],res[8];
  char op;
  int calc,num_a, num_b;
  uint8_t num_calc_i;

  lcd_init(cursor_aceso);
  lcd_goto(0,0);
  lcd_wrstr("LAB. PROCESSADOR");
  lcd_goto(0,1);
  lcd_wrstr("MIGUEL & OTAVIO");
  HAL_Delay(5000); //DEIXAR 5000

  lcd_default();

  op = 0;
  num_calc_i=num_a=num_b=0;

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  for(int i=10; i<14; i++){
		  HAL_Delay(10);
		  GPIOA->BSRR = (1 << i);

		  for(int j=6; j<10; j++){
			  if(GPIOA->IDR & (1<<j)){
				  if(op == '='){

					  lcd_default();
					  tecla_pres = '$';
					  for(int i=0; i<9; i++){
						  num_calc[i]=0;
						  res[i]=0;
					  }
					  op = 0;
					  num_calc_i=num_b=num_a=0;

				  }
				  tecla_pres = teclado[j-6][i-10];
			  }

			  while(GPIOA->IDR & (1<<j)){}
		  	  }


		  HAL_Delay(10);
		  GPIOA->BRR = (1 << i);

	  }



	  if(tecla_pres != '$'){



		  switch(tecla_pres){
			  case '0' ... '9':
			  	  lcd_wrchar(tecla_pres);
			  	  num_calc[num_calc_i] = tecla_pres;
			  	  num_calc_i++;
			  break;

			  case '/':
			  	  lcd_wrchar(tecla_pres);

			  	  op = '/';
			  	  num_a = atoi(num_calc);
			  	  num_calc_i = 0;

			  	  for(int i=0; i<6; i++) num_calc[i]=0;

			  break;

			  case '*':
			  	  lcd_wrchar(tecla_pres);

			  	  op = '*';
			  	  num_a = atoi(num_calc);
			  	  num_calc_i = 0;

			  	  for(int i=0; i<6; i++) num_calc[i]=0;
			  break;

			  case '-':
			  	  lcd_wrchar(tecla_pres);
			  	  op = '-';

			  	  num_a = atoi(num_calc);
			  	  num_calc_i = 0;

			  	  for(int i=0; i<6; i++) num_calc[i]=0;
			  break;

			  case '+':
			  	  lcd_wrchar(tecla_pres);

			  	  op = '+';
			  	  num_a = atoi(num_calc);
			  	  num_calc_i = 0;

			  	  for(int i=0; i<6; i++) num_calc[i]=0;

			  break;

			  case '=':
				  num_b = atoi(num_calc);

				  if(op == '+') calc = num_a + num_b;
				  if(op == '-') calc = num_a - num_b;
				  if(op == '*') calc = num_a * num_b;
				  if(op == '/') {
					  if(num_b == 0){
						  lcd_goto(10,1);
						  sprintf(res,"NaN 0!");
						  lcd_wrstr(res);
						  op = '=';
						  break;

					  }

					  calc = num_a / num_b;

					  lcd_goto(10,1);
					  sprintf(res,"%d", (calc));
					  lcd_wrstr(res);

					  calc = ((num_a % num_b)*1000)/num_b;

					  sprintf(res,".%d", (calc));
					  lcd_wrstr(res);
					  op = '=';
					  break;
				  }




				  lcd_goto(10,1);
				  sprintf(res,"%d", (calc));
				  lcd_wrstr(res);
				  op = '=';

			  break;

			  case 'c':
				  lcd_default();


				  tecla_pres = '$';
				  for(int i=0; i<9; i++){
					  num_calc[i]=0;
					  res[i]=0;
				  }
				  op = 0;
				  num_calc_i=num_b=num_a=0;
			  break;

		  }

		  tecla_pres = '$';
	  }





  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 PA10 PA11
                           PA12 PA13 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12|GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PA6 PA7 PA8 PA9 */
  GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void udelay(void)
{
	int tempo = 7;
	while(tempo--);
}

void delayus(int tempo)
{
	while(tempo--) udelay();
}

// Recebe 4 bits e coloca bit0 --> D4 LCD
//						  bit1 --> D5 LCD
//						  bit2 --> D6 LCD
//						  bit3 --> D7 LCD

void lcd_send4bits(uint8_t dat)
{
	if((dat & (1<<0)) == 0) d4_0; else d4_1;
	if((dat & (1<<1)) == 0) d5_0; else d5_1;
	if((dat & (1<<2)) == 0) d6_0; else d6_1;
	if((dat & (1<<3)) == 0) d7_0; else d7_1;

}

//Comando de 4 bits
void lcd_wrcom4(uint8_t com)
{
	lcd_send4bits(com);
	rs_0;
	en_1;
	delayus(5);
	en_0;
	HAL_Delay(5);
}

// Comando de 8 bits
// com D7...D4 D3 ... D0
void lcd_wrcom(uint8_t com)
{
	lcd_send4bits(com>>4);
	rs_0;
	en_1;
	delayus(5);
	en_0;

	lcd_send4bits(com);
	en_1;
	delayus(5);
	en_0;
	HAL_Delay(5);


}

void lcd_wrchar(char ch)
{
	lcd_send4bits(ch>>4);
	rs_1;
	en_1;
	delayus(5);
	en_0;
	HAL_Delay(5);

	lcd_send4bits(ch);
	en_1;
	delayus(5);
	en_0;
	HAL_Delay(5);
}

void lcd_init(uint8_t cursor)
{
	lcd_wrcom4(3);
	lcd_wrcom4(3);
	lcd_wrcom4(3);
	lcd_wrcom4(2);

	lcd_wrcom(0x28);
	lcd_wrcom(cursor);
	lcd_wrcom(0x06);
	lcd_wrcom(0x01);
}

void lcd_clear (void)
{
	lcd_wrcom(0x01);
}

void lcd_goto(uint8_t x, uint8_t y)
{
	uint8_t com = 0x80;
	if(y==0) com = 0x80 + x;
	if(y==1) com = 0xC0 + x;
	if(y==2) com = 0x90 + x;
	if(y==3) com = 0xD0 + x;

	lcd_wrcom(com);
}

void lcd_wrstr(char *str)
{
	while(*str) lcd_wrchar(*(str++));
}

void lcd_default(void){


	  lcd_clear ();

	  lcd_goto(0,0);
	  lcd_wrstr("OP=> ");
	  lcd_goto(0,1);
	  lcd_wrstr("RESULTADO= ");

	  lcd_goto(5,0);

}


/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
