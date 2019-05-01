var modem;

var slider;

var button;
var canvas;
function preload(){
modem = loadSound("ModemSound.mp3",playAudio);

}
function setup(){
  canvas = createCanvas(windowWidth,windowHeight);
  canvas.position(0,0);
  canvas.style('z-index', '-1');

  button = createButtom("play");
  buttom.mousePressed(toggledAudio);



  slider = createSlider(0,3,1,0.01

  modem.setVolume(0.5);


}

function toggledAudio() {
   if (modem.isPlaying()){
      modem.play();
      buttom.html("puase");


   } else {
        modem.pause();
        buttom.html("play")
}

function draw() {
    background(200);
    

}
