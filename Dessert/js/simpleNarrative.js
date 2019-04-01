var canvas;

var gif_loadImg , gif_createImg;

var userName;
var title;
var greeting;
var nameInput;
var firstOption;
var secondOption;
var thirdOption;
var fudgeOption;
var basicOption;
var fudgeChocoOption;
var fudgeStrawOption;
var basicChocoOption;
var basicStrawOption;



let bg;
let bg2;
let y = 0;

var song;
function preload() {
  song = loadSound('Ice-cream-truck-music.mp3');
}

function setup() {
  // The background image must be the same size as the parameters
  // into the createCanvas() method. In this program, the size of
  // the image is 720x400 pixels.
  bg = loadImage('newshopgreen.jpg');
  song.loop(); // song is ready to play during setup() because it was loaded during preload
  canvas = createCanvas(windowWidth,windowHeight);
  canvas.position(0,0);
  canvas.style('z-index', '-1');
  gif_loadImg = loadImage("walkingGil.gif");
  gif_createImg = createImg("walkingGirl.gif");
  beginning();
}

function mousePressed() {
  if ( song.isPlaying() ) { // .isPlaying() returns a boolean
    song.pause(); // .play() will resume from .pause() position
    //background(255,0,0);
  } else {
    song.play();
    //background(0,255,0);
  }
}


function draw() {
  background(bg);
  gif_createImg.position(450, 350);
}



/////////////////////////////////////
////////scene start functions///////
///////////////////////////////////

function beginning(){
  greeting = createP("HELLO! PLEASE ENTER YOUR NAME IN TO START THE GAME")
  nameInput = createInput();
  nameInput.changed(startStory);

}
function startStory() {
//  bg = loadImage('icecream.jpg');

  greeting.hide();
  nameInput.hide();
  bg = loadImage('icecream.jpg');
  gif_createImg.hide();
  //bg.hide();
  //background(loadImage('icecream.jpg'));
  userName = createElement('h1', nameInput.value());
  title = createElement('h1', 'WHAT WOULD YOU LIKE THE BASE OF YOUR ICECREAM TO BE?')
  firstOption = createButton("VANILLA");
  secondOption = createButton("CHOCALATE");
  thirdOption = createButton("STRAWBERRY");

  firstOption.mousePressed(Vanilla);
  secondOption.mousePressed(Chocalate);
  thirdOption.mousePressed(Strawberry);

}
function Strawberry() {
  thirdOption.hide();
  secondOption.hide();
  firstOption.hide();
  bg = loadImage('strawberry.jpg');

  greeting.hide();
  title.html("YUMM STRAWBERRY, LETS CHOSE YOUR TOPPING NOW");
  fudgeStrawOption = createButton(" FUDGE AND SPRINKLES");
  fudgeStrawOption.position(320,250);
  basicStrawOption = createButton(" PLAIN ");
  basicStrawOption.position(520,250);
  fudgeStrawOption.mousePressed(FudgeStraw);
  basicStrawOption.mousePressed(BasicStraw);
  nameInput.hide();

}
function FudgeStraw() {
  firstOption.hide();
  secondOption.hide();
  fudgeStrawOption.hide();
  basicStrawOption.hide();
  thirdOption.hide();
  bg = loadImage('fudgestrawberry.jpg');

  title.html("ENJOY, YOUR STARWBERRY ICE-CREAM WITH SPRINKLES!");
  canvas = createCanvas(200,200);
  canvas.position(350,250);
  greeting.hide();


  nameInput.hide();
}



function BasicStraw() {
  basicStrawOption.hide();
  fudgeStrawOption.hide();
  firstOption.hide();
  secondOption.hide();
  thirdOption.hide();
  bg = loadImage('basicstraw.png');
  title.html("ENJOY, YOUR STRAWBERRY ICE-CREAM!");
  canvas = createCanvas(200,200);
  canvas.position(350,250);
  greeting.hide();


}


function Chocalate() {
  firstOption.hide();
  secondOption.hide();
  thirdOption.hide();
  bg = loadImage('choco.png');
  greeting.hide();
  title.html('YUMMM CHOCALATE, LETS CHOSE YOUR TOPPING NOW');
  fudgeChocoOption = createButton("FUDGE AND SPRINKLES");
  fudgeChocoOption.position(320,250);
  //fudgeChocoOption.width(200,200);
  basicChocoOption = createButton(" PLAIN");
  basicChocoOption.position(500,250);
  fudgeChocoOption.mousePressed(FudgeChoco);
  basicChocoOption.mousePressed(BasicChoco);
  nameInput.hide();
}

function FudgeChoco() {
  firstOption.hide();
  secondOption.hide();
  fudgeChocoOption.hide();
  basicChocoOption.hide();
  thirdOption.hide();
  bg = loadImage('nutsandfudge.jpg');
  title.html("ENJOY, YOUR CHOCALATE ICE-CREAM WITH FUDGE AND NUTS!");
  canvas = createCanvas(300,300);
  canvas.position(350,250);
  greeting.hide();
  fudgeOption.hide();
  basicOption.hide();
  nameInput.hide();
}



function BasicChoco() {
  basicChocoOption.hide();
  fudgeChocoOption.hide();
  firstOption.hide();
  secondOption.hide();
  thirdOption.hide();
  bg = loadImage('basiccho.jpg');
  title.html("ENJOY, YOUR CHOCALATE ICE-CREAM!");
  canvas = createCanvas(300,300);
  canvas.position(350,250);
  greeting.hide();
}




function Vanilla() {

  firstOption.hide();
  secondOption.hide();
  thirdOption.hide();
  bg = loadImage('vanilla3.png');
  greeting.hide();
  title.html('WOW, WHAT A DELICIOUS CHOICE! Lets chose your topping now!');
  fudgeOption = createButton("Hot Fudge and Sprinkles");
  fudgeOption.position(320,250);
  basicOption = createButton("Basic vanilla")
  basicOption.position(540,250);
  fudgeOption.mousePressed(Fudge);
  basicOption.mousePressed(Basic);
  nameInput.hide();


}

function Fudge() {
  firstOption.hide();
  secondOption.hide();
  fudgeOption.hide();
  basicOption.hide();
  thirdOption.hide();
  bg = loadImage('hot fudge and cherry.png');
  title.html("ENJOY, YOUR VANILLA ICE-CREAM WITH FUDGE AND SPRINKLES!");
  canvas = createCanvas(300,300);
  canvas.position(350,250);
  greeting.hide();
  fudgeOption.hide();
  basicOption.hide();
  nameInput.hide();
}

function Basic() {
  basicOption.hide();
  fudgeOption.hide();
  firstOption.hide();
  secondOption.hide();
  thirdOption.hide();
  bg = loadImage('basic.png');
  title.html("ENJOY, YOUR VANILLA ICE-CREAM!");
  canvas = createCanvas(300,300);
  canvas.position(350,250);
  greeting.hide();
}



function windowResized(){
  canvas = createCanvas(windowWidth, windowHeight);

}
