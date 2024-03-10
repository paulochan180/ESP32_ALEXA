
#ifdef ARDUINO_ARCH_ESP32
#include <WiFi.h>                 // INCLUSÃO DA BIBLIOTECA PARA USAR O PROTOCOLO WI-FI
#else
#include <ESP8266WiFi.h>
#endif
#include <Espalexa.h>              //INCLUSÃO DA BIBLIOTECA ESPALEXA

//----------------------------------ASSOCIANDO OS RELÉS COM AS ENTRADAS GPIO's DO ESP32---------------------------------------------------------------------------------------------------------
#define R1 2        //GPIO 2
#define R2 4        //GPIO 4
#define R3 5        //GPIO 5
#define R4 12       //GPIO 12
#define R5 13       //GPIO 13
#define R6 14       //GPIO 14
#define R7 15       //GPIO 15
#define R8 18       //GPIO 18
#define R9 19       //GPIO 19
#define R10 21      //GPIO 21

//----------------------------------PROTOTIPOS--------------------------------------------------------------------------------------------------------------------------------------------------
boolean connectWifi();
//----------------------------------CHAMADA DAS FUNÇÕES-----------------------------------------------------------------------------------------------------------------------------------------
void firstLightChanged(uint8_t brightness);
void secondLightChanged(uint8_t brightness);
void thirdLightChanged(uint8_t brightness);
void fourthLightChanged(uint8_t brightness);
void fifthLightChanged(uint8_t brightness);
void sixthLightChanged(uint8_t brightness);
void seventhLightChanged(uint8_t brightness);
void eighthLightChanged(uint8_t brightness);
void ninthLightChanged(uint8_t brightness);
void tenthLightChanged(uint8_t brightness);

//----------------------------------CONFIGURAÇÕES DA REDE WIFI (SSID e SENHA)----------------------------------------------------------------------------------------------------------------------

const char* ssid = "SSID DA REDE WI-FI";
const char* password = "SENHA DA REDE WI-FI";
//----------------------------------NOMES DOS DISPOSITIVOS PARA INCLUSÃO NA ALEXA-----------------------------------------------------------------------------------------------------------------
String Device_1_Name = "VARANDA";
String Device_2_Name = "SALA";
String Device_3_Name = "BALCÃO";
String Device_4_Name = "COZINHA";
String Device_5_Name = "AREA DE SERVIÇO";
String Device_6_Name = "CORREDOR";
String Device_7_Name = "QUARTO DE CASAL";
String Device_8_Name = "ESCRITÓRIO";
String Device_9_Name = "VENTILADOR DO ESCRITÓRIO";
String Device_10_Name = "BOMBA";

boolean wifiConnected = false;

Espalexa espalexa;
//----------------------------------DEFINIÇÃO INICIAL DAS CONFIGURAÇÕES DOS PINOS DA PLACA RELÉS-------------------------------------------------------------------------------------------------
void setup()
{
  Serial.begin(115200);

  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(R5, OUTPUT);
  pinMode(R6, OUTPUT);
  pinMode(R7, OUTPUT);
  pinMode(R8, OUTPUT);
  pinMode(R9, OUTPUT);
  pinMode(R10, OUTPUT);

  //---------------------------------INICIANDO AS CONEXÕES WIFI-----------------------------------------------------------------------------------------------------------------------------------
  wifiConnected = connectWifi();

  if (wifiConnected)
  {

    //-------------------------------DEFININDO OS DISPOSITIVOS LOCAIS DENTRO DA ALEXA----------------------------------------------------------------------------------------------------------------
    espalexa.addDevice(Device_1_Name, firstLightChanged); 
    espalexa.addDevice(Device_2_Name, secondLightChanged);
    espalexa.addDevice(Device_3_Name, thirdLightChanged);
    espalexa.addDevice(Device_4_Name, fourthLightChanged);
    espalexa.addDevice(Device_5_Name, fifthLightChanged); 
    espalexa.addDevice(Device_6_Name, sixthLightChanged);
    espalexa.addDevice(Device_7_Name, seventhLightChanged);
    espalexa.addDevice(Device_8_Name, eighthLightChanged);
    espalexa.addDevice(Device_9_Name, ninthLightChanged);
    espalexa.addDevice(Device_10_Name, tenthLightChanged);

    espalexa.begin();

  }

  else
  {
    while (1)
    {
      Serial.println("Cannot connect to WiFi. Please check data and reset the ESP.");
      delay(2500);
    }
  }

}
//------------------------------------MANIPULAÇÃO DOS DISPOSITIVOS (RELÉS DE 1 AO 10) DENTRO DA ALEXA--------------------------------------------------------------------------------------------------
void loop()
{
  espalexa.loop();
  delay(1);
}

//-------------------------------------CHAMANDO AS FUNÇÕES DOS RELES NO PROGRAMA PRINCIPAL--------------------------------------------------------------------------------------------------------------
void firstLightChanged(uint8_t brightness)
{
  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R1, HIGH);
      Serial.println("Device1 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R1, LOW);
    Serial.println("Device1 OFF");
  }
}

void secondLightChanged(uint8_t brightness)
{

  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R2, HIGH);
      Serial.println("Device2 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R2, LOW);
    Serial.println("Device2 OFF");
  }
}

void thirdLightChanged(uint8_t brightness)
{

  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R3, HIGH);
      Serial.println("Device3 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R3, LOW);
    Serial.println("Device3 OFF");
  }
}

void fourthLightChanged(uint8_t brightness)
{

  if (brightness)
  {

    if (brightness == 255)
    {
      digitalWrite(R4, HIGH);
      Serial.println("Device4 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R4, LOW);
    Serial.println("Device4 OFF");
  }
}

void fifthLightChanged(uint8_t brightness)
{
  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R5, HIGH);
      Serial.println("Device5 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R5, LOW);
    Serial.println("Device5 OFF");
  }
}

void sixthLightChanged(uint8_t brightness)
{
  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R6, HIGH);
      Serial.println("Device6 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R6, LOW);
    Serial.println("Device6 OFF");
  }
}

void seventhLightChanged(uint8_t brightness)
{ 
  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R7, HIGH);
      Serial.println("Device7 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R7, LOW);
    Serial.println("Device7 OFF");
  }
}

void eighthLightChanged(uint8_t brightness)
{
  if (brightness)
  {

    if (brightness == 255)
    {
      digitalWrite(R8, HIGH);
      Serial.println("Device8 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R8, LOW);
    Serial.println("Device8 OFF");
  }
}

void ninthLightChanged(uint8_t brightness)
{
  if (brightness)
  {
    if (brightness == 255)
    {
      digitalWrite(R9, HIGH);
      Serial.println("Device9 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R9, LOW);
    Serial.println("Device9 OFF");
  }
}

void tenthLightChanged(uint8_t brightness)
{
  if (brightness)
  {

    if (brightness == 255)
    {
      digitalWrite(R10, HIGH);
      Serial.println("Device10 ON");
    }
    //Serial.print("ON, brightness ");
    //Serial.println(brightness);
  }
  else
  {
    digitalWrite(R10, LOW);
    Serial.println("Device10 OFF");
  }
}

//--------------------------------MENSAGENS DE INTERAÇÃO COM A REDE WIFI EM CASO DE FALHA OU SUCESSO---------------------------------------------------------------------------------------------
boolean connectWifi()
{
  boolean state = true;
  int i = 0;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println("Conectando ao WiFi");

  Serial.print("Conectando...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (i > 20) {
      state = false; break;
    }
    i++;
  }
  Serial.println("");
  if (state) {
    Serial.print("Conectado a");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  }
  else {
    Serial.println("Conexão falhou.");
  }
  return state;
}
