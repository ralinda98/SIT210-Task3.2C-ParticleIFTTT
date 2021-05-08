int lightSensor = A0;

bool checkSun = false;
int lightValue = 0;

void setup()
{
    pinMode(lightSensor, INPUT);
}

void loop()
{
    lightValue = analogRead(lightSensor);
    
    if(lightValue >= 50)
    {
        if(checkSun == false)
        {
            checkSun = true;
            Particle.publish("Status", "Sun is shining");
        }
    }
    else
    {
        if(checkSun == true)
        {
            checkSun = false;
            Particle.publish("Status", "No light shining");
        }
    }
    delay(5000);
}