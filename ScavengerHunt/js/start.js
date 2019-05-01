var canvas;
var clickMe;
var bg;
var y;
var x;
var z;
var background;

var yesbtn;
var yesbtn1;

var nobtn;
var nobtn1;

var startbtn;

var mainbtn;

var gif_loadImg, gif_createImg;

 // Declare variable 'img'.
//let myFont;




function setup()  {
  //background(255,204,0);
  myFont = loadFont('Hwyl fawr Hello.otf');
  //createCanvas(windowWidth,windowHeight);


 }
var t;
var w;
var text1;
 function myFunction() {
   canvas = createCanvas(windowWidth,windowHeight);
   //background(255,204,0);
   text('Hello');
   y = document.getElementById("demo").innerHTML;
   //x = document.getElementById("myDiv").innerHTML;
   z = document.getElementById("myDiv").style.display = "none";
   //t = document.body.style.background = "gold";




   //text1.size(35);
   //text1.position(500,400);

   yesbtn = createButton("YES");
   yesbtn.mousePressed(YesButton);
   yesbtn.position(400,500);

   nobtn = createButton("NO");
   nobtn.mousePressed(NoButton);
   nobtn.position(800,500);
   beginning();
   mainbtn.hide();
   //gif_loadImg.postion();
   gif_createImg.position(1300,1000);

 }

 var s;
 var b;
 var t;

 var f;
function beginning() {

  background(255,215,0);
  text("Hello,", 100, 50);
  text("How are you today?" ,190,100) ;
  text(" I was thinking we should play a game", 300, 150);
  text("What do you think?",190,200);
}

function Words() {

  text("YESS LETS DO THIS!", 200, 50);
  text("NOW, ARE YOU READY FOR SOME FUN, CAUSE I KNOW I AM",400,100) ;
  text("BUT WAIT,", 100, 200);
  text("DO YOU THINK YOUR'RE SMART ENOUGH TO PLAY THIS GAME?",350,250);
}

function Words2() {

  text("OH WELL OK", 100, 50);
  text("I GUESS IN THE MEANTIME YOU CAN",250,100) ;
  text("ENJOY THIS GIF", 100, 200);
  text("OR HEAD BACK TO MAIN PAGE, WHATEVER FLOATS YOUR BOAT",300,250);
}

function confident2() {

  text("OH OKAY,", 200, 50);
  text("MAYBE THIS GAME ISN'T FOR YOU",200,100) ;
  text("I SUGGEST YOU LEAVE", 180, 150);

}



function confident() {

  text("WOW! YOU SURE SEEM CONFIDENT", 200, 50);
  text("LET'S SEE HOW YOU DO",400,100) ;
  text("GOOD LUCK", 100, 200);
  text("AND REMEMBER, HAVE FUN!",350,250);
}


function draw() {
  textSize(30);
  textAlign(CENTER);
  textFont(myFont);
}

function YesButton() {
  //canvas = createCanvas(windowWidth,windowHeight);
  background(0,0,255);
  yesbtn.hide();
  nobtn.hide();
  Words();
  yesbtn1 = createButton("YES");
  yesbtn1.mousePressed(YesBtn);
  yesbtn1.position(400,500);
  nobtn1 = createButton("NO");
  nobtn1.mousePressed(NoBtn);
  nobtn1.position(800,500);
}
var hope;

function YesBtn() {
  background(0,255,0);
  yesbtn1.hide();
  nobtn1.hide();
  confident();

  hope = createButton("CONTINUE");
  hope.mousePressed(hopebtn);
  hope.position(500,500);

  //starbtn = createButton("START");
  //starbtn.mousePressed(startStory);
  //starbtn.position(500,500);
}
var puzzle;
var img;


function link(url, winName, options) {
  winName && open(url, winName, options) || (location = url);
}
function hopebtn() {
  window.location.href = "https://fareeharahman.github.io/SmartyPants/index.html";
}



function NoBtn() {
    background(32,178,170);
    yesbtn1.hide();
    nobtn1.hide();
    confident2();
    awkward();

  }

function NoButton() {
  //canvas = createCanvas(windowWidth,windowHeight);
  background(255,160,122);
  yesbtn.hide();
  nobtn.hide();
  Words2();
  gif_loadImg = loadImage("ferb.gif");
  gif_createImg = createImg("ferb.gif");
  image(gif_loadImg, 50, 50);
  gif_createImg.position(800, 100);

  mainbtn = createButton("MAIN");
  mainbtn.mousePressed(myFunction);
  mainbtn.position(500,500);
}
