var bubbles = [];
let t = 0; // time variable

let bg;
let y = 0;







function setup() {
    bg = loadImage('white.jpg');
    createCanvas(windowWidth, windowHeight);

    noStroke();
    fill(40, 200, 40);
}

function draw() {
    //background(0);
    background(bg);

    stroke(255, 156, 282);
    line(0, y, width, y);

    y++;
    if (y > height) {
      y = 0;

    }




    let t = frameCount / 60; // update time

    // create a random number of snowflakes each frame
    for (let i = 0; i < random(5); i++) {
      snowflakes.push(new snowflake()); // append snowflake object
    }

    // loop through snowflakes with a for..of loop
    for (let flake of snowflakes) {
      flake.update(t); // update snowflake position
      flake.display(); // draw snowflake
    }

    // make a x and y grid of ellipses
      for (let x = 0; x <= width; x = x + 30) {
        for (let y = 0; y <= height; y = y + 30) {
          // starting point of each circle depends on mouse position
          let xAngle = map(mouseX, 0, width, -4 * PI, 4 * PI, true);
          let yAngle = map(mouseY, 0, height, -4 * PI, 4 * PI, true);
          // and also varies based on the particle's location
          let angle = xAngle * (x / width) + yAngle * (y / height);

          // each particle moves in a circle
          let myX = x + 20 * cos(2 * PI * t + angle);
          let myY = y + 20 * sin(2 * PI * t + angle);
          ellipse(myX, myY, 10); // draw particle
          fill(40, 200, 40);
        }
      }

      t = t + 0.20; // update time

      bubbles.forEach((bubble) => {
          bubble.update();
          bubble.show();
      });


}


let snowflakes = []; // array to hold snowflake objects


// snowflake class
function snowflake() {
  // initialize coordinates
  this.posX = 0;
  this.posY = random(-50, 0);
  this.initialangle = random(0, 2 * PI);
  this.size = random(2, 5);

  // radius of snowflake spiral
  // chosen so the snowflakes are uniformly spread out in area
  this.radius = sqrt(random(pow(width / 2, 2)));

  this.update = function(time) {
    // x position follows a circle
    let w = 0.10; // angular speed
    let angle = w * time + this.initialangle;
    this.posX = width / 2 + this.radius * sin(angle);

    // different size snowflakes fall at slightly different y speeds
    this.posY += pow(this.size, 0.5);

    // delete snowflake if past end of screen
    if (this.posY > height) {
      let index = snowflakes.indexOf(this);
      snowflakes.splice(index, 1);
    }
  };

  this.display = function() {
    ellipse(this.posX, this.posY, this.size);
  };
}

function mousePressed() {


    //const size = random(10,50)
    const pos = createVector(mouseX, mouseY) // x, y
    const vel = createVector(random(-4,4),
                             random(-4,4));
    const col = (color(
        random(0,255),
        random(0,255),
        random(0,255)
    ));

    const radius = random(50,150);

    bubbles.push(
        new Bubble(pos,vel,col,radius)
    );



 }
function keyPressed() {
  bubbles.splice(0, 1);

 }


var Bubble = (function () {

    function Bubble(pos, vel, col, radius) {
        this.pos = pos;
        this.vel = vel;
        this.col = col;
        this.radius = radius;

    }

    Bubble.prototype.show = function () {
        noStroke();
        fill(this.col);
        ellipse(this.pos.x, this.pos.y, this.radius, this.radius);
    }

    Bubble.prototype.update = function () {
        this.pos.add(this.vel);
        this.edges();
    }

    Bubble.prototype.edges = function () {
        if (this.pos.x - (this.radius / 2) < 0 || this.pos.x + (this.radius / 2) > width) {
            this.vel.x *= -1;
        }

        if (this.pos.y - (this.radius / 2) < 0 || this.pos.y + (this.radius / 2) > height) {
            this.vel.y *= -1;
        }
    }



    return Bubble;
})();
