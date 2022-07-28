
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI();                   // Invoke custom library with default width and height

//TFT_eSPI tft = TFT_eSPI(240, 320);       // Could invoke custom library declaring width and height

unsigned long targetTime = 0;
byte red = 31;
byte green = 0;
byte blue = 0;
byte state = 0;
unsigned int colour = red << 11; // Colour order is RGB 5+6+5 bits each
void pricer(char*title,char*price);
void pricer_with_promotion(char*title,char*price_promotion,char*price);
void setup(void) {
  Serial.begin(9600);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_WHITE);
  char*title = "Name produkt";
  char price_Promotion[] = "500";
  char*prise = "250";

  pricer_with_promotion(title,price_Promotion,prise);
  //pricer(title,prise); // Fill the screen with rainbow colours

}


void loop() {
   
   }

void pricer_with_promotion(char*title,char*price_promotion,char*price)
{
  colour = TFT_CYAN ;

  tft.fillRect(190, 190, 200, 200, colour);
  
  tft.setTextSize(1);          
  tft.setTextColor(TFT_CYAN );
  tft.setCursor(15, 18, 2);    
  tft.println("Company name");
  tft.setTextSize(1);         
  tft.setTextColor(TFT_BLACK);
  tft.setCursor(26, 75, 2);   
  tft.println(title);
  tft.println(title); 
  tft.setCursor(200, 68, 4);    
  tft.println("Old prise");
  tft.setCursor(200, 90, 4);    
  tft.println(price_promotion);
  
  tft.setCursor(200, 140, 4);    
  tft.println("Price:");  
  tft.setCursor(200, 170, 7);    
  tft.println(price);   
}

void pricer(char*title,char*price)
{
   for (int i = 50; i > 0; i--) {
    colour = TFT_BLACK;
    tft.drawFastHLine(0, i, tft.width(), colour); 
   }
  tft.setTextSize(1);           
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(25, 25, 4);   
  tft.println("Company name");
  tft.setTextSize(1);           
  tft.setTextColor(TFT_BLACK);
  tft.setCursor(36, 75, 4);    
  tft.println(title);  
  tft.setCursor(200, 140, 4);   
  tft.println("Price:"); 
  tft.setCursor(200, 170, 7);    
  tft.println(price);  
  
  
}
