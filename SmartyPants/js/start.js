var song;
var canvas;
var clickMe;
var bg;
 // Declare variable 'img'.
let myFont;
let dragon;


function preload() {
  start = createButton("START");
  start.mousePressed(Continue);
}

function setup()  {


  // The background image must be the same size as the parameters
  // into the createCanvas() method. In this program, the size of
  // the image is 720x400 pixels.
  //bg = loadImage('newshopgreen.jpg');
  //song.loop(); // song is ready to play during setup() because it was loaded during preload
  canvas = createCanvas(windowWidth,windowHeight);
  canvas.position(0,0);
  canvas.style('z-index', '-1');
  //gif_loadImg = loadImage("walkingGil.gif");
  //gif_createImg = createImg("walkingGirl.gif");
  beginning();
}
 function beginning() {
   Continue = createButton("Continue");
   Continue.mousePressed(Continue);
   Continue.position(500,500);
 }

 function Continue() {
   fill(0);
   text('ONE BORING AFTERNOON YOU DECIDE TO EXPLORE A CAVE IN SEARCH OF THE JEWEL', x, 80);
 }
//function draw() {
  //backgound(178,150,0);
  //document.getElementById("demo").innerHTML
  //color(178,150,0);
  //canvas = createCanvas(windowWidth,windowHeight);
  //background(178,150,0);

//}
//function myFuction() {
  //document.getElementById("demo").innerHTML
  //x = document.getElementById("myDiv").innerHTML;
  //if(x.style.display==="none") {
    //x.style.display="block";
  //} else {
    //x.style.display="none";
  //}
//}

//}


  //Continue = createButton("Continue");
  //Continue.mousePressed(Continue);
  //Continue.position(500,500);





function drawWords(x) {
  //dragon.position(100,100);
  fill(0);
  text('ONE BORING AFTERNOON YOU DECIDE TO EXPLORE A CAVE IN SEARCH OF THE JEWEL', x, 80);
  dragon = loadImage("pictures/dog.jpg")

  fill(0);
  text('OF SHALWARIA BUT unfournately, DUE TO YOU STUPIDNESS, YOU TRIPPED' , x, 150);

  fill(0);
  text('AND SET OFF AN ALARAM. NOW YOU HAVE TO GET OUT OF THERE  FAST!', x, 220);

  fill(0);
  text('OTHERWISE THE THREE HEADED DRAGON WILL CAPTURE YOU.',x,290);


}


//function draw() {
  //textAlign(CENTER);
  //drawWords(width * 0.5);
  //textSize(35);
  //textFont(myFont);

//}//



  //"ONLY WAY TO GET OUT IS TOO FIND the THREE KEYS THAT OPEN";
// "THE DOOR. EACH KEY IS LOCKED IN A SAFE THAT WILL ONLY OPEN";
  //"AFTER COMPLETING EACH CHALLENGE.   NOW REMEMBER YOU DONT";
// "HAVE MUCH TIME. SO  HURRY UP AND GOOD LUCK!"
