//Declaração dos pinos do 7 segment display
int SEG_A = 2;
int SEG_B = 4;
int SEG_C = 6;
int SEG_D = 7;
int SEG_E = 8;
int SEG_F = 3;
int SEG_G = 5;

//Declaração dos pinos do DIP Switch 
int primeiro = 9;
int segundo = 10;
int terceiro = 11;
int quarto = 12;

void setup(){
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);

  pinMode(primeiro, INPUT);
  pinMode(segundo, INPUT);
  pinMode(terceiro, INPUT);
  pinMode(quarto, INPUT);
}

//Funções com cada lógica obtida pelo Mapa de Karnaugh para acender determinado LED do 7 segment display

void acendeA(int a, int b, int c, int d) {
  digitalWrite(SEG_A, (!b && !d) || (b && c) || (a && !c && !d) || (a && !b && !c) || (!a && c && d) || (!a && b && d));
}

void acendeB(int a, int b, int c, int d) {
  digitalWrite(SEG_B, (!a && !b) || (!b && !d) || (a && !c && d) || (!a && !c && !d) || (!a && c && d));
}

void acendeC(int a, int b, int c, int d) {
  digitalWrite(SEG_C, (!a && !c) || (a && !b) || (a && !c && d) || (!a && c && d) || (!a && b && c));
}

void acendeD(int a, int b, int c, int d) {
  digitalWrite(SEG_D, (a && !c) || (!a && !b && !d) || (!a && !b && c) || (b && c && !d) || (a && !b && d) || (b && !c && d));
}

void acendeE(int a, int b, int c, int d) {
  digitalWrite(SEG_E, (!a && !b && !d) || (a && c) || (a && !b && !d) || (a && b && !c) || (!a && c && !d));
}

void acendeF(int a, int b, int c, int d) {
  digitalWrite(SEG_F, (!c && !d) || (!a && b && !c) || (b && c && !d) || (a && !b && d) || (a && c));
}

void acendeG(int a, int b, int c, int d) {
  digitalWrite(SEG_G, (!a && b && !c) || (a && !b && !c) || (a && d) || (!a && !b && c) || (c && !d));
}

void loop(){
  //Lê as entradas do DIP Switch
  int a = digitalRead(primeiro);
  int b = digitalRead(segundo);
  int c = digitalRead(terceiro);
  int d = digitalRead(quarto);
  
  //Chama as funções para acender ou não determinado LED
  acendeA(a, b, c, d);
  acendeB(a, b, c, d);
  acendeC(a, b, c, d);
  acendeD(a, b, c, d);
  acendeE(a, b, c, d);
  acendeF(a, b, c, d);
  acendeG(a, b, c, d);
}