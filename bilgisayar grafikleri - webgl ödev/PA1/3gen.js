var gl;//, program;

var colors = [0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,1, 0,0,1, 0,0,1,];

window.onload = function init() {

	var canvas = document.getElementById("myCanvas");
    gl = canvas.getContext( "experimental-webgl" );
    if (!gl) { alert("WebGL isn’t available"); }
	
	
	
    gl.viewport(0, 0, canvas.width, canvas.height); 
    gl.clearColor(1.0, 1.0, 1.0, 1.0);

	var vertices =	[
		-0.75, 0.3, 0.0,		//rectangle first vertex
		-0.75, -0.3, 0.0,		//rectangle second vertex
		-0.25, -0.3, 0.0,		//rectangle third vertex
		-0.25, 0.3, 0.0,		//rectangle fourth vertex
		0.5, 0.4811, 0.0,		//triangle first vertex
		0.1875, -0.4811, 0.0,	//triangle second vertex
		0.8125, -0.4811, 0.0,	//triangle third vertex
	];

	indices = [4,5,6, 4,6,7,   0,1,2,];
	

	// Create a new buffer object
	var vertex_buffer = gl.createBuffer();	
	var index_buffer = gl.createBuffer();

	// Bind an empty array buffer to it
	gl.bindBuffer(gl.ARRAY_BUFFER, vertex_buffer);
	gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, index_buffer);

	// Pass the vertices data to the buffer
	gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW);
	// Pass the indices data to the buffer
	gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, new Uint16Array(indices), gl.STATIC_DRAW);
	
	// Unbind the buffer
	gl.bindBuffer(gl.ARRAY_BUFFER, null);
	// İndex için de tekrar yazmaya gerek duyabilir miyiz? Target farklı olduğundan yazmaya gerek vardır
	gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, null);
		
	// Bind vertex buffer object
	gl.bindBuffer(gl.ARRAY_BUFFER, vertex_buffer);
	
	// Bind index buffer object
	gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, index_buffer);
	
	
	
	
	
	
	shaderProgram = initShaders(gl, "vertex", "fragment"); 
	gl.useProgram(shaderProgram);
	
	
	
	
	
    var coordinates = gl.getAttribLocation(shaderProgram, "coordinates"); 
    gl.vertexAttribPointer(coordinates, 3, gl.FLOAT, false, 0, 0); 
    gl.enableVertexAttribArray(coordinates);
	
	
	
	var color_buffer = gl.createBuffer();
	gl.bindBuffer(gl.ARRAY_BUFFER, color_buffer);
	gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(colors), gl.STATIC_DRAW);
	gl.bindBuffer(gl.ARRAY_BUFFER, null);
	gl.bindBuffer(gl.ARRAY_BUFFER, color_buffer);	
    var color = gl.getAttribLocation(shaderProgram, "color"); 
    gl.vertexAttribPointer(color, 3, gl.FLOAT, false, 0, 0); 
    gl.enableVertexAttribArray(color);
	

    window.addEventListener("keydown", changeColor); 
	
	myCanvas.addEventListener("click",moveRectangle);
	
	
    render();
}

function render(time_ms) {
    
    gl.clear(gl.COLOR_BUFFER_BIT); 

    var colorPosition = gl.getUniformLocation(shaderProgram, "vColor");
    gl.uniform4fv(colorPosition, colors);

	// Draw the triangle
	gl.drawElements(gl.TRIANGLES, 3, gl.UNSIGNED_SHORT,0);
    gl.drawArrays(gl.LINE_LOOP, 0, 4);
	
    requestAnimationFrame(render);
}


function changeColor(e){

    if(e.keyCode == "84"){
        //color = [Math.random(), Math.random(), Math.random(), 1];
		var difColorRed = Math.random();
		var difColorGreen = Math.random();
		var difColorBlue = Math.random();
		
		colors = [0,0,0, 0,0,0, 0,0,0, 0,0,0, 
		difColorRed,difColorGreen,difColorBlue,
		difColorRed,difColorGreen,difColorBlue,
		difColorRed,difColorGreen,difColorBlue,];
		
		var color_buffer = gl.createBuffer();
		gl.bindBuffer(gl.ARRAY_BUFFER, color_buffer);
		gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(colors), gl.STATIC_DRAW);
		gl.bindBuffer(gl.ARRAY_BUFFER, null);
		gl.bindBuffer(gl.ARRAY_BUFFER, color_buffer);	
		var color = gl.getAttribLocation(shaderProgram, "color"); 
		gl.vertexAttribPointer(color, 3, gl.FLOAT, false, 0, 0); 
		gl.enableVertexAttribArray(color);
	}
}

function moveRectangle(e){
	
	var x=e.pageX/320 -1;
	var y;
	
	if(e.pageY/180 < 1)
		y = 1 -e.pageY/180;
	else
		y = -(e.pageY/180 -1);
	
//	alert("X=" + x + " Y=" + y);
	
	var vertices =	[
		x-0.25, y+0.3, 0.0,		//rectangle first vertex
		x-0.25, y-0.3, 0.0,		//rectangle second vertex
		x+0.25, y-0.3, 0.0,		//rectangle third vertex
		x+0.25, y+0.3, 0.0,		//rectangle fourth vertex
		0.5, 0.4811, 0.0,		//triangle first vertex
		0.1875, -0.4811, 0.0,	//triangle second vertex
		0.8125, -0.4811, 0.0,	//triangle third vertex
	];


	indices = [4,5,6, 4,6,7,   0,1,2,];
	

	// Create a new buffer object
	var vertex_buffer = gl.createBuffer();	
	var index_buffer = gl.createBuffer();

	// Bind an empty array buffer to it
	gl.bindBuffer(gl.ARRAY_BUFFER, vertex_buffer);
	gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, index_buffer);

	// Pass the vertices data to the buffer
	gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(vertices), gl.STATIC_DRAW);
	// Pass the indices data to the buffer
	gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, new Uint16Array(indices), gl.STATIC_DRAW);
	
	// Unbind the buffer
	gl.bindBuffer(gl.ARRAY_BUFFER, null);
	// İndex için de tekrar yazmaya gerek duyabilir miyiz? Target farklı olduğundan yazmaya gerek vardır
	gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, null);
		
	// Bind vertex buffer object
	gl.bindBuffer(gl.ARRAY_BUFFER, vertex_buffer);
	
	// Bind index buffer object
	gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, index_buffer);
	
    var coordinates = gl.getAttribLocation(shaderProgram, "coordinates"); 
    gl.vertexAttribPointer(coordinates, 3, gl.FLOAT, false, 0, 0); 
    gl.enableVertexAttribArray(coordinates);

}

function initShaders(gl, vertexShaderId, fragmentShaderId) {
	var vertShdr;
	var fragShdr;

	var vertElem = document.getElementById(vertexShaderId);

	vertShdr = gl.createShader(gl.VERTEX_SHADER);
	gl.shaderSource(vertShdr, vertElem.text);
	gl.compileShader(vertShdr);

	var fragElem = document.getElementById(fragmentShaderId);
	fragShdr = gl.createShader(gl.FRAGMENT_SHADER);
	gl.shaderSource(fragShdr, fragElem.text);
	gl.compileShader(fragShdr);



	var program = gl.createProgram();
	gl.attachShader(program, vertShdr);
	gl.attachShader(program, fragShdr);
	gl.linkProgram(program);


	return program;
}