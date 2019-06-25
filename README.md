# Midi Mosaic :musical_keyboard:

![Midi Mosiac Blue](http://mclemens.mgserver.org/Images/IMG_3551.jpg)

The Midi Mosaic is an interactive art exhibit for a children’s museum that doubles as an interactive MIDI controller via capacitive touch photographs.

The Midi Mosaic is currently located at the Curious Kids' Museum in St. Joseph, Michigan.  Be sure to check it out if you get the chance! :bowtie:

Demos of the project can be found on YouTube by clicking the following two images:

<a href="http://www.youtube.com/watch?feature=player_embedded&v=lzz4zSDs-3s
" target="_blank"><img src="http://img.youtube.com/vi/lzz4zSDs-3s/0.jpg" 
alt="Midi Mosaic Demo (Madeon)" width="240" height="180" border="10" /></a>

<a href="http://www.youtube.com/watch?feature=player_embedded&v=ryv_76FB_y8
" target="_blank"><img src="http://img.youtube.com/vi/ryv_76FB_y8/0.jpg" 
alt="Midi Mosaic Demo (Harder Better Faster Stronger)" width="240" height="180" border="10" /></a>


## Getting Started

Due to the nature of this project, the code isn't necessarily transferrable to other domains unless you have a Midi Mosaic (and if there are more of these projects out there, definitely let me know and show off your MIDI controller! :smile: )

## Built With

* [Teensy 3.6] - The microcontroller used
* [BlueSMiRF Silver] - The Bluetooth Modem used
* [Indium Tin Oxide Coated PET] – Used to create a capacitive glass
* [WS2812B RGB 5050 LED Strip] – LED strips for each of the boxes
* [RSP-320-5 300W 5V Power Supply] – Supplies power to this baby
* [MPR 121 Cap Touch Module] – Converts the user’s “touch” into a trigger in the software
* [TXB0108 Level Converter] – Take 3.3V to 5V and vice versa

## CAD Model

If anyone is interested, I used OnShape to sketch everything in CAD.  The model can be found [here](https://cad.onshape.com/documents/8cc8a91fe985116ffbdf6bbd/w/6f97be81eeae7664b89baed9/e/5e68668bd3000bb2f4dac299).

## Programming Lights

I created a little web app in order to program all the lights (because generative programming definitely needed to happen with the sheer number of lights used in this project).  You can play around with the web app [here](https://mclemcrew.github.io/LED-Code-Generator-for-Midi-Mosaic/) and as always, the code for the web app is open source and can be found [here](https://github.com/mclemcrew/LED-Code-Generator-for-Midi-Mosaic).

## Authors

* **Michael Clemens (mclemcrew)**

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
