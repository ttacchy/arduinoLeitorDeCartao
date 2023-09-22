//Incluir as bibliotecas necessárias
#include <SPI.h>
#include <SD.h>

const int chipSelect = 10; //pino utilizado pelo terminal CS do módulo

void setup(){
Serial.begin(9600); //inicializa o monitor Serial
while(!Serial){ //aguarda a conexão da porta serial;
}
//imprime texto no monitor serial
Serial.println("Inicializando o cartão de memória...");
Serial.println("**********************************");
pinMode(SS, OUTPUT); //define pinMode como saída

if(!SD.begin(chipSelect)){ //se o cartão não for reconhecido, faz:
//imprime texto no monitor serial
Serial.println("Cartão de memória falhou ou não está presente!");
return;   //não executa o restante do código
}
//imprime texto no monitor serial
Serial.println("Cartão de memória inicializado com sucesso!");
Serial.println("*************************************");
Serial.println("Mensagem do arquivo de texto que está no cartão de memória:");
Serial.println(); //quebra de linha no serial

SDFile dataFile = SD.open("arquivo.txt"); //dataFile recebe o conteúdo do arquivo
// Caso tenha mais de um arquivo, abre um arquivo por vez

if(dataFile){ //se existirem dados, faz:
while(dataFile.available()){ //enquanto houver conteúdo a ser lido, faz
Serial.write(dataFile.read()); //escreve na serial as informações do arquivo
}
//encerra a leitura, fechar o arquivo atual para poder abrir um outro
dataFile.close();
}
else{     //se não existirem dados, faz
//imprime texto do erro no monitor serial
Serial.println("Erro ao abrir o arquivo!");
} 
}

void loop(){
//não necessita repetir a ação
}