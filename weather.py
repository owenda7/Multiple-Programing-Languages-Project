from PIL import Image, ImageDraw, ImageFilter, ImageFont

def main():
    buildBackground((getWeather("weather.csv")))

def getWeather(file):
    weatherData = []
    data = ""
    # Open the csv file
    with open(file) as inFile:
        for line in inFile:
            for char in line:
                if char != ',':
                    data += char
                else:
                    weatherData.append(data)
                    data = ""
            weatherData.append(data[:-1])
            data = ""
    return weatherData


def buildBackground(weatherData):
    DAYS = 7
    # open background image
    background = Image.open('images/background.png')
    icons = []
    # open icons based on user input
    for i in range(0, DAYS):
        icons.append(Image.open('images/'+weatherData[(3*i)]+'.png'))

    # constants used for spacing icons
    ICONX = 365
    ICONY = 700

    final = background.copy()
    # paste icons onto copy of background image
    for i in range(0, DAYS):
        final.paste(icons[i],((i+1)*ICONX+i*5,ICONY))

    # constants used for spacing text
    TEMPX = 390
    TEMPY = 1000

    # NOTE: If error on ImageFont.truetype call, download below for font
    # download font: https://github.com/JotJunior/PHP-Boleto-ZF2/blob/master/public/assets/fonts/arial.ttf
    tempFont = ImageFont.truetype("arial.ttf", 170)
    temps = []
    # create 7 text boxes with high and low temperatures
    for i in range(0, DAYS):
        temps.append(ImageDraw.Draw(final))
        temperatures = "" + weatherData[(1+(3*i))] + "\n" + weatherData[2+(3*i)]
        temps[i].multiline_text(((i+1)*TEMPX-i*20, TEMPY),temperatures, font=tempFont)

    # save final photo
    final.save('final.png')
    final.show()

main()
