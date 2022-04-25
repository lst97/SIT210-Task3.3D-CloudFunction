int LED_PIN = D2;
int DELAY_TIME = 1000; // 1s
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", led_handler);
  Serial.begin(9600);
}


void led_handler(String event, String data)
{
  Serial.print("handler activated!");

  if(data == "wave"){
    for(int i = 0; i < 3; i++){
      digitalWrite(LED_PIN, HIGH);
      delay(DELAY_TIME);
      digitalWrite(LED_PIN, LOW);
      delay(DELAY_TIME);
    }
    return;
  }

  if(data == "pat"){
   for(int i = 0; i < 3; i++){
      digitalWrite(LED_PIN, HIGH);
      delay(DELAY_TIME / 4);
      digitalWrite(LED_PIN, LOW);
      delay(DELAY_TIME / 4);
    }
  }
}

void loop() {

}
