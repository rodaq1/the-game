#include <stdio.h>
#include <led.cpp>
#include <melodies.cpp>
#include <button.cpp>
#include <esp_random.h>
#include <seven_segment.cpp>

Led leds[4] = {
    {GPIO_NUM_4}, //zlta
    {GPIO_NUM_18}, //cervena
    {GPIO_NUM_19}, //modra
    {GPIO_NUM_21}, //zelena
};

Button btns[4] = {
    {GPIO_NUM_14}, //zlty
    {GPIO_NUM_27}, //cerveny
    {GPIO_NUM_26}, //modry
    {GPIO_NUM_25} //zeleny
};

Buzzer buzzer = Buzzer(GPIO_NUM_23);

SevenSegment sevenSegment = SevenSegment(GPIO_NUM_16, GPIO_NUM_17, GPIO_NUM_33, GPIO_NUM_32, GPIO_NUM_22, GPIO_NUM_12, GPIO_NUM_13);

int calculateTimeToPress(int score) {
    const int baseTimeToPress = 5000;
    const int minTimeToPress = 250; 
    const int decrementPerScore = 500; 

    int timeToPress = baseTimeToPress - (score * decrementPerScore);

    if (timeToPress < minTimeToPress) {
        timeToPress = minTimeToPress;
    }

    return timeToPress;
}

int score = 0;

extern "C"
void app_main(void) {
    Buzzer buzzer(GPIO_NUM_23);
    playGameStartMelody(buzzer);
    sevenSegment.display(0);
    while (true) {
        int randomIndex = esp_random() % 4;

        leds[randomIndex].changeState(1);

        bool correctButtonPressed = false;
        bool wrongButtonPressed = false;
        int timeToPress = calculateTimeToPress(score); //zacne s intervalom 10 sekund, po kazdom vyhratom kole sa skrati
        int elapsedTime = 0;
        while (elapsedTime < timeToPress) {
            for (int i = 0; i < 4; i++) {
                if (btns[i].isPressed()) {
                    if (i == randomIndex) {
                        correctButtonPressed = true;
                    } else {
                        wrongButtonPressed = true;
                    }       
                break;
            }
        }
        if (wrongButtonPressed || correctButtonPressed) {
            break; 
        }
            vTaskDelay(pdMS_TO_TICKS(100)); 
            elapsedTime += 100;
        }

        leds[randomIndex].changeState(0);

        if (correctButtonPressed) {
            score++;
            playSuccessMelody(buzzer);
        } else {
            playGameOverMelody(buzzer);
            sevenSegment.clear(); 
            break;
        }
        sevenSegment.display(score);
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
}