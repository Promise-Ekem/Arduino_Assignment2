int buzzerPin=8;
int segmentPins[] = {2, 3, 4, 5, 6, 7, 9};   // a, b, c, d, e, f, g
int numSegments = sizeof(segmentPins)/sizeof(segmentPins[0]);
 
// The pattern for each digit. 1 = segment ON, 0 = segment OFF.
byte digits[10][7] = {
    {1, 1, 1, 1, 1, 1, 0},   // 0
    {0, 1, 1, 0, 0, 0, 0},   // 1
    {1, 1, 0, 1, 1, 0, 1},   // 2
    {1, 1, 1, 1, 0, 0, 1},   // 3
    {0, 1, 1, 0, 0, 1, 1},   // 4
    {1, 0, 1, 1, 0, 1, 1},   // 5
    {1, 0, 1, 1, 1, 1, 1},   // 6
    {1, 1, 1, 0, 0, 0, 0},   // 7
    {1, 1, 1, 1, 1, 1, 1},   // 8
    {1, 1, 1, 1, 0, 1, 1},   // 9
};
void showDigit(int n) {
    if (n < 0 || n > 9) return;
    for (int i = 0; i < numSegments; i++) {
        digitalWrite(segmentPins[i], digits[n][i]);
    }
}
void setup() {
      Serial.begin(9600);
 
    // Set every segment pin as OUTPUT.
    for (int i = 0; i < numSegments; i++) {
        pinMode(segmentPins[i], OUTPUT);
    }
   
    Serial.println("===Beeping Countdown Starting===");
    int counter=9;
    
    while(counter >= 1){
      Serial.print("Counting: ");
      Serial.println(counter);
      Serial.println("BEEP!");

      // call the show_digit function and pass in counter
      showDigit(counter);
      tone(buzzerPin,1000,500);
      delay(2000);

      counter-=1;
     }

  showDigit(counter);
  tone(buzzerPin,500,1000);        
  
  // longer completion tone
  Serial.println("===Countdown Complete===");
}

void loop() {


}