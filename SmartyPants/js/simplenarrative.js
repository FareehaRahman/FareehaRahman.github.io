var canvas;

var userName;

//screen text
var title;
var firstOption;
var secondOption;

//input
var slider;
var greeting;
var nameInput;

var growingPlanetBool = false;


var startOver;

//images

var dancingBaby;
var babyX = 0;

var babySpeed = 2;

var babySlider;

var babyScale;
function preload(){

}

function setup() {
	canvas = createCanvas(windowWidth, windowHeight);
	canvas.position(0,0);
	canvas.style('z-index', '-1');
	background(120);
	beginning();
}

function draw() {
	background(0);
	babyAnim();

	print(babyX);
	if(growingPlanetBool == true){
		growingPlanet();
	}
}


/////////////////////////////////////
////////scene start functions///////
///////////////////////////////////

function beginning(){
	background(0);

	dancingBaby = createImg("dancingBaby.gif");
	 babySlider = createSlider(50, 600, 150);
	greeting = createP("Please type your name and press enter");
	nameInput = createInput();

	//check and see if the user pressed enter
	//then trigger startStory function
	nameInput.changed(startStory);

}

function babyAnim(){
	//babyX = babyX + babySpeed;
	babyScale = babySlider.value();
	dancingBaby.position(babyX, 200);
	dancingBaby.style('width', babySlider.value() + 'px');
	if(babyX > windowWidth +100){
		babyX = 0;
	}

	dancingBaby.mousePressed(startStory);
}


function startStory(){
	//background(0);
	greeting.hide();
	nameInput.hide();
	dancingBaby.hide();
	userName = createElement('h1', nameInput.value());

	title = createElement('h1', 'Get home before the sun sets');

	//create link want two arguments: where to link and the text
	firstOption = createA("#", "walk home");
	createElement('br');
	secondOption = createA("#", "walk towards the sun");

	//check to see if the user has clicked on one of the options
	//trigger attached function
	firstOption.mousePressed(walkHome);
	secondOption.mousePressed(walkToSun);


}

//the end of the game
function walkHome(){
	background(0);
	firstOption.hide();
	secondOption.hide();
	userName.hide();

	//change the text for the title
	title.html("You have gone home. Good Night.");

	//startOver = createA("index.html", "Start Over")
	//firstOption.mousePressed(startOver);
}

function walkToSun(){
	background(0);
	userName.hide();
	title.html(nameInput.value() + ', you walk towards the sun and see a planet');

	firstOption.html("walk closer to the sun");
	secondOption.html("Walk towards the planet");

	firstOption.mousePressed(closerToSun);
	secondOption.mousePressed(planetElements);
}

function closerToSun(){
	firstOption.hide();
	secondOption.hide();

	title.html(nameInput.value() + ', drifting towards the sun');
}


function planetElements(){
	firstOption.hide();
	secondOption.hide();
	 slider = createSlider(0, 255, 0);

	title.html(nameInput.value() + " control the size of the planet");
	growingPlanetBool = true;
}


/////////////////////////////////////
////////animated functions//////////
///////////////////////////////////

function growingPlanet(){

	 background(120);
	 //slider requires at least two arguments
	//createSlider(min value, max value, starting value)
  	print(slider.value());
  	fill(slider.value());
  	ellipse(400, 400, slider.value(), slider.value());
}





function windowResized(){
  canvas = createCanvas(windowWidth, windowHeight);

}
