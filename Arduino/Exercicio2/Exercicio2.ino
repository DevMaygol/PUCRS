int digito[8][3] = {
 { LOW, LOW, LOW }, // 0
 { LOW, LOW, HIGH }, // 1
 { LOW, HIGH, LOW }, // 2
 { LOW, HIGH, HIGH }, // 3
 { HIGH, LOW, LOW }, // 4
 { HIGH, LOW, HIGH }, // 5
 { HIGH, HIGH, LOW }, // 6
 { HIGH, HIGH, HIGH } // 7
};
int LED1 = 11;
int LED2 = 12;
int LED3 = 13;
int num = 0;

void setup() {
 pinMode(LED1, OUTPUT);
 pinMode(LED2, OUTPUT);
 pinMode(LED3, OUTPUT);
}
void loop() {
 digitalWrite(LED1, digito[num][0]);
 digitalWrite(LED2, digito[num][1]);
 digitalWrite(LED3, digito[num][2]);
 num++;
 if (num > 7)
 num = 0;
 delay (1000);
}
