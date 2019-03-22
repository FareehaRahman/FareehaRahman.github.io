var canvas;
var name;

//input
var slider;
var greeting;
var nameInput;

var startStoryBool = false;

function preload() {

}

function setup() {
  create = createCanvas(windowWidth, windowHeight);
  canvas.position(0,0);
  canvas.style('z-index', '-1');
  background(120);
  beginning();

}


function draw() {
 if(startStoryBool == true) {
   startStory();
 }
}

function beginning(){
  greeting = createP("PLease type your name and press enter");
  nameInput = createInput();
  //check and see if the user pressed enter
  nameInput.changed(startStory);
}

function startStoryElements(){
  startStoryBool = true;
  nameInput.hide();
  greeting.hide();
  slider = createSlider(0,255,0);
  name = createElement('h1', nameInput.value());
  createP(nameInput.value() + "control the size of the ellipse")
  startStoryBool = true;

}

function startStory(){
  background(120);
  // slider requires at least two arguments
  //creatSlider(min value, max value, starting value, ending value)
  print(slider.value());
  fill(slider.value());
  ellipse(400, 400, slider.value(), slider.value());
}

function windowResizd() {
  canvas = createCanvas(windowWidth,windowHeight)
  background(0);
}
