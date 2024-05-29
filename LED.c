/*Keypad Interfacing  with Microcontroller*/

#include <REGX51.H>
#include "string.H"  //for strcmp: to check whether entered pwd matches the stored pwd

#define keypad  P1
#define LCD_dat P2

sbit rs =P3^0; //control pins
sbit en =P3^1;

sbit device = P3^2; //green LED for correct password
sbit red_led = P3^3; //red LED for wrong password
sbit buzzer = P3^3; //buzzer for wrong password

void dely(unsigned int dly);
void lcd_cmd(unsigned char ch);
void lcd_data(unsigned char ch);
void lcd_str(unsigned char *str);
char get_keypad_key(void);

void main(void)
{
    char KeyVal =0; //value entered by the user is updated here
    unsigned int KeyCnt =0; //user entered pwd must be counted
    unsigned int CmpPassword =0; //the string comparison value is copied, if both pwd are same, value is 0
    char DefaultPassword[5]="6666"; //when correct pwd is set, the bulb glows, on second entry the bulb goes off
    char EnteredPassword[5];
    device = 0; //device initial status
    red_led = 0; //red LED initial status
    buzzer = 0; //buzzer initial status
    lcd_cmd(0x38);
    lcd_cmd(0x0C);//lcd interfacing
    lcd_cmd(0x06);
    lcd_cmd(0x01);
    
    while(1)
    {    //main logic
        lcd_cmd(0x80); //lcd command for distance upto first row
        lcd_str("Enter Password: ");
        
        KeyVal = get_keypad_key(); //reading the input keypad value
        
        if(KeyVal != 0) //checks each value of entered pwd and stores in it and checks the condn 
        { 
            EnteredPassword[KeyCnt] = KeyVal;    //first entered pwd value to the array is updated
            lcd_cmd(0xc0+KeyCnt); //when user enters first key
            lcd_data('*');    //second row should display star - to hide pwd
            KeyCnt =  KeyCnt + 1; //to get next value         
        }           
                    
        if(KeyCnt == 4) //condn to check if the keyval reached the max keycnt
        {
            lcd_cmd(0x01);
            KeyCnt =0;            //6666 - clearing for next time operation
            CmpPassword = strcmp(DefaultPassword,EnteredPassword);
                            
            if(CmpPassword == 0)
            {
                device = ~device; // Device control for correct password
                lcd_cmd(0x80); //to display in first row
                lcd_str("Correct Password"); //display string
                dely(500);   
            }
            else
            {
                red_led = 1; // Turn on red LED for wrong password
                buzzer = 1; // Turn on buzzer for wrong password
                lcd_cmd(0x80);
                lcd_str("Wrong Password");
                dely(500);   
                red_led = 0; // Turn off red LED after a delay
                buzzer = 0; // Turn off buzzer after a delay
            }
        }                       
    }
}

char get_keypad_key(void)
{
    char key_val =0;
           keypad = 0xFE; //ROW1 =0            
          if(keypad == 0xee) // button 1
                    {
           key_val = '1';
                    }   
          if(keypad == 0xde) // button 2
                    {
           key_val = '2';
                    }   
                     if(keypad == 0xbe) // button 3
                    {
           key_val = '3';
                    }   
                    
                    keypad = 0xFD; //ROW2 =0
                    if(keypad == 0xED) // button 4
                    {
                    key_val = '4';
                    }   
                    if(keypad == 0xDD) // button 5
                    {
                    key_val = '5';
                    }   
                     if(keypad == 0xBD) // button 6
                    {
                    key_val = '6';
                    }   
                    
                    keypad = 0xFB; //ROW3 =0
                    if(keypad == 0xEB) // button 7
                    {
                    key_val = '7';
                    }   
                    if(keypad == 0xDB) // button 8
                    {
                    key_val = '8';
                    }   
                     if(keypad == 0xBB) // button 9
                    {
                    key_val = '9';
                    }   
                    
                        keypad = 0xF7; //ROW3 =0
                    if(keypad == 0xE7) // button *
                    {
                    key_val = '*';
                    }   
                    if(keypad == 0xD7) // button 0
                    {
                    key_val = '0';
                    }   
                     if(keypad == 0xB7) // button #
                    {
                    key_val = '#';
                    }   
    return key_val;
}


void lcd_str(unsigned char *str)
{
    unsigned int loop =0;
    for(loop =0; str[loop]!= '\0'; loop++)
    {
        lcd_data(str[loop]);
    }
}
void lcd_data(unsigned char ch)
{
    LCD_dat = ch;
    rs = 1;  // data
    en = 1;
    dely(10);
    en = 0;
}

void lcd_cmd(unsigned char ch)
{
    LCD_dat = ch;
    rs = 0;  // cmd
    en = 1;
    dely(10);
    en = 0;
}
void dely(unsigned int dly)
{
    unsigned int loop =0;
    unsigned int delay_gen =0;
    for(loop =0; loop < dly; loop++)
    for(delay_gen =0; delay_gen < 1000; delay_gen++); /* delay */
}
