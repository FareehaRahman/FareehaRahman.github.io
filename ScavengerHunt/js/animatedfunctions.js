/////////////////////////////////////
////////animated functions///////////
///////////////////////////////////

function growingPlanet(){

	 background(120);
	 //slider requires at least two arguments
	//createSlider(min value, max value, starting value)
  	print(slider.value());
  	fill(slider.value());
  	ellipse(400, 400, slider.value(), slider.value());
}
