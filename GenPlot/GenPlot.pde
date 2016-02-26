/*
* Código para visualizar portas analógicas no computador, como um osciloscópio.
* Este código pode ser usado/distribuido através dos termos da GNU
* Saiba mais em: <http://www.gnu.org/licenses/>.
*/

import processing.serial.*;
int SERIAL_SPEED = 9600;
PFont f;
Serial port; // Cria objeto para a classe Serial
int val; // Variável para guardar dados da vindos da porta serial
int[] values;
/*
* Deve-se ver a porta serial que está conectada. No meu caso é normalmente a COM4
* que é a segunda da lista
*/
void setup(){
  size(660, 480); //cria uma tela de 640 x 480
  //o comando abaixo abre a porta que a placa está conectada e usa a mesma velocidade (SERIAL_SPEED)
  println(Serial.list());
  port = new Serial(this, Serial.list()[1], SERIAL_SPEED);
  values = new int[width];
  smooth();
  f = createFont("Arial",16,true); // Arial, 16 point, anti-aliasing on
}

int getY(int val) {
  return (int)(val); // vou substituir o 1023.f
}

void draw(){
  while (port.available() >= 3) {
  if (port.read() == 0xff) {
    val = (port.read() << 8) | (port.read());
  }
}

for (int i=0; i<width-1; i++)
  values[i] = values[i+1];
values[width-1] = val;
background(0);
stroke(255);
for (int x=1; x<width; x++) {
  line(width-x, height-1-getY(values[x-1]),
  width-1-x, height-1-getY(values[x]));
  text("Valor atual = ", 505, 460);
  text(val, 590,460);
}
textFont(f,14); //aqui escrevemos as frases de valores mínimo e máximo
fill(255);
text("Nível máximo = 1023",20,20);
text("Nível mínimo = 0",20,460);
println(val);
}
