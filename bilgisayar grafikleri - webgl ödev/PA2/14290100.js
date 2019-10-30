"use strict";

var canvas,gl,program,projectionMatrix,modelViewMatrix,instanceMatrix,modelViewMatrixLoc;


var vertices = [
	vec4( -0.5, -0.5,  0.5, 1.0 ),
    vec4( -0.5,  0.5,  0.5, 1.0 ),
    vec4( 0.5,  0.5,  0.5, 1.0 ),
    vec4( 0.5, -0.5,  0.5, 1.0 ),
    vec4( -0.5, -0.5, -0.5, 1.0 ),
    vec4( -0.5,  0.5, -0.5, 1.0 ),
    vec4( 0.5,  0.5, -0.5, 1.0 ),
    vec4( 0.5, -0.5, -0.5, 1.0 )
];


// RGBA colors
var vertexColors = [
    vec4( 0.0, 0.0, 0.0, 1.0 ),  // black
    vec4( 1.0, 0.0, 0.0, 1.0 ),  // red
    vec4( 1.0, 1.0, 0.0, 1.0 ),  // yellow
    vec4( 0.0, 1.0, 0.0, 1.0 ),  // green
    vec4( 0.0, 0.0, 1.0, 1.0 ),  // blue
    vec4( 1.0, 0.0, 1.0, 1.0 ),  // magenta
    vec4( 1.0, 1.0, 1.0, 1.0 ),  // white
    vec4( 0.0, 1.0, 1.0, 1.0 )   // cyan
];

var torsoId = 0, torsoId2=11, headId  = 1,head1Id = 1,head2Id = 10,leftUpperArmId = 2,leftLowerArmId = 3,rightUpperArmId = 4,rightLowerArmId = 5,leftUpperLegId = 6,leftLowerLegId = 7,rightUpperLegId = 8,rightLowerLegId = 9;
var torsoHeight = 5.0,torsoWidth = 3.8, upperArmHeight = 3.0,lowerArmHeight = 2.0,upperArmWidth  = 1.0,lowerArmWidth  = 0.5,upperLegWidth  = 1.0,lowerLegWidth  = 0.5,lowerLegHeight = 2.0,upperLegHeight = 3.0,headHeight = 2.0,headWidth = 2.0;

var numNodes = 10,numAngles = 11,angle=0,theta = [0, 0, 0, 0, 0, 0, 180, 0, 180, 0, 0, 0],numVertices = 24,stack = [],figure = [];

var i=0; 
while(i<numNodes)
{
	figure[i] = createNode(null, null, null, null);
	i++;
}


var vBuffer,cBuffer;
var modelViewLoc;

var pointsArray = [],colors = [];


//-------------------------------------------

// Remmove when scale in MV.js supports scale matrices
function scale4(a, b, c)
{
   var result = mat4();
   result[0][0] = a;
   result[1][1] = b;
   result[2][2] = c;
   return result;
}

//--------------------------------------------


function createNode(transform, render, sibling, child)
{
    var node =
	{
		transform: transform,
		render: render,
		sibling: sibling,
		child: child,
    }
    return node;
}

/*function(event) {
	if(event.keyCode==100 || event.keyCode==68)
	{
        theta[0] +=10;
        initNodes(torsoId);
	}
    };
	*/
	
var asd=0;
function initNodes(Id)
{

    var m = mat4();

    switch(Id) 
	{

		case torsoId:
		case torsoId2:
		
			m = mult(m, rotate(theta[torsoId], 1, 0, 0))
			m = mult(m, rotate(theta[torsoId2], 0, 1, 0));

		
	
		figure[torsoId] = createNode( m, torso, null, headId );
		break;

		case headId:
		case head1Id:
		case head2Id:


			m = translate(0.0, torsoHeight+0.5*headHeight, 0.0);
			m = mult(m, rotate(theta[head1Id], 1, 0, 0))
			m = mult(m, rotate(theta[head2Id], 0, 1, 0));
			m = mult(m, translate(0.0, -0.5*headHeight, 0.0));
			figure[headId] = createNode( m, head, leftUpperArmId, null);
		break;


		case leftUpperArmId:

			m = translate(-(torsoWidth+upperArmWidth), 0.9*torsoHeight, 0.0);
			m = mult(m, rotate(theta[leftUpperArmId], 1, 0, 0));
			figure[leftUpperArmId] = createNode( m, leftUpperArm, rightUpperArmId, leftLowerArmId );
		break;

		case rightUpperArmId:

			m = translate(torsoWidth+upperArmWidth, 0.9*torsoHeight, 0.0);
			m = mult(m, rotate(theta[rightUpperArmId], 1, 0, 0));
			figure[rightUpperArmId] = createNode( m, rightUpperArm, leftUpperLegId, rightLowerArmId );
		break;

		case leftUpperLegId:

			m = translate(-(torsoWidth+upperLegWidth), 0.1*upperLegHeight, 0.0);
			m = mult(m , rotate(theta[leftUpperLegId], 1, 0, 0));
			figure[leftUpperLegId] = createNode( m, leftUpperLeg, rightUpperLegId, leftLowerLegId );
		break;

		case rightUpperLegId:

			m = translate(torsoWidth+upperLegWidth, 0.1*upperLegHeight, 0.0);
			m = mult(m, rotate(theta[rightUpperLegId], 1, 0, 0));
			figure[rightUpperLegId] = createNode( m, rightUpperLeg, null, rightLowerLegId );
		break;

		case leftLowerArmId:
	
			m = translate(0.0, upperArmHeight, 0.0);
			m = mult(m, rotate(theta[leftLowerArmId], 1, 0, 0));
		    figure[leftLowerArmId] = createNode( m, leftLowerArm, null, null );
		break;

		case rightLowerArmId:

			m = translate(0.0, upperArmHeight, 0.0);
			m = mult(m, rotate(theta[rightLowerArmId], 1, 0, 0));
			figure[rightLowerArmId] = createNode( m, rightLowerArm, null, null );
		break;

		case leftLowerLegId:

		m = translate(0.0, upperLegHeight, 0.0);
		m = mult(m, rotate(theta[leftLowerLegId], 1, 0, 0));
		figure[leftLowerLegId] = createNode( m, leftLowerLeg, null, null );
		break;

		case rightLowerLegId:

		m = translate(0.0, upperLegHeight, 0.0);
		m = mult(m, rotate(theta[rightLowerLegId], 1, 0, 0));
		figure[rightLowerLegId] = createNode( m, rightLowerLeg, null, null );
		break;

    }
	
}


function traverse(Id) {

   if(Id == null) return;
   stack.push(modelViewMatrix);
   modelViewMatrix = mult(modelViewMatrix, figure[Id].transform);
   figure[Id].render();
   if(figure[Id].child != null) traverse(figure[Id].child);
    modelViewMatrix = stack.pop();
   if(figure[Id].sibling != null) traverse(figure[Id].sibling);
}

function torso() {

    instanceMatrix = mult(modelViewMatrix, translate(0.0, 0.5*torsoHeight, 0.0) );
    instanceMatrix = mult(instanceMatrix, scale4( torsoWidth, torsoHeight, torsoWidth));
    cizme();
	/*
	gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(instanceMatrix));
	var i =0;
    while(i<6)
	{
		gl.drawArrays(gl.TRIANGLE_FAN, 4*i, 4);
		i++;
	}
	*/
}



function head() {

    instanceMatrix = mult(modelViewMatrix, translate(0.0, 0.5 * headHeight, 0.0 ));
	instanceMatrix = mult(instanceMatrix, scale4(headWidth, headHeight, headWidth) );
    cizme();
	/*
	gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(instanceMatrix));
	var i =0;
    while(i<6)
	{
		gl.drawArrays(gl.TRIANGLE_FAN, 4*i, 4);
		i++;
		
	}
	*/	
}

function leftUpperArm() {

    instanceMatrix = mult(modelViewMatrix, translate(2.5, 0.5 * upperArmHeight, 0.0) );
	instanceMatrix = mult(instanceMatrix, scale4(upperArmWidth, upperArmHeight, upperArmWidth) );
    cizme();
	/*
	gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(instanceMatrix));
	var i =0;
    while(i<6)
	{
		gl.drawArrays(gl.TRIANGLE_FAN, 4*i, 4);
		i++;
	}
	*/	
}

function leftLowerArm() {

    instanceMatrix = mult(modelViewMatrix, translate(2.5, 0.5 * lowerArmHeight, 0.0) );
	instanceMatrix = mult(instanceMatrix, scale4(lowerArmWidth, lowerArmHeight, lowerArmWidth) );
    cizme();
	/*
	gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(instanceMatrix));
	var i =0;
    while(i<6)
	{
		gl.drawArrays(gl.TRIANGLE_FAN, 4*i, 4);
		 i++;
	}
	*/
}

function rightUpperArm() {

    instanceMatrix = mult(modelViewMatrix, translate(-2.5, 0.5 * upperArmHeight, 0.0) );
	instanceMatrix = mult(instanceMatrix, scale4(upperArmWidth, upperArmHeight, upperArmWidth) );
    cizme();
	/*
	 gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(instanceMatrix));
	var i =0; 
    while(i<6)
	{
		gl.drawArrays(gl.TRIANGLE_FAN, 4*i, 4);
		i++;
	}
	*/
}

function rightLowerArm() {

    instanceMatrix = mult(modelViewMatrix, translate(-2.5, 0.5 * lowerArmHeight, 0.0) );
	instanceMatrix = mult(instanceMatrix, scale4(lowerArmWidth, lowerArmHeight, lowerArmWidth) );
    cizme();
	/*
	gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(instanceMatrix));
	var i =0;
	while( i<6)
	{
	   gl.drawArrays(gl.TRIANGLE_FAN, 4*i, 4);
	   i++;
	}
   */
   
}

function  leftUpperLeg() {

    instanceMatrix = mult(modelViewMatrix, translate(2.5, 0.5 * upperLegHeight, 0.0) );
	instanceMatrix = mult(instanceMatrix, scale4(upperLegWidth, upperLegHeight, upperLegWidth) );
    cizme();
	/*
	gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(instanceMatrix));
	var i =0;
	while( i<6)
	{
	   gl.drawArrays(gl.TRIANGLE_FAN, 4*i, 4);
	   i++;
	}
	*/
	
}

function leftLowerLeg() {

    instanceMatrix = mult(modelViewMatrix, translate( 2.5, 0.5 * lowerLegHeight, 1.0) );
	instanceMatrix = mult(instanceMatrix, scale4(lowerLegWidth, lowerLegHeight, lowerLegWidth) );
    cizme();
    /*
	gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(instanceMatrix));
	var i =0;
	while( i<6)
	{
	   gl.drawArrays(gl.TRIANGLE_FAN, 4*i, 4);
	   i++;
	}
	*/
	
}

function rightUpperLeg() {

    instanceMatrix = mult(modelViewMatrix, translate(-2.5, 0.5 * upperLegHeight, 0.5) );
	instanceMatrix = mult(instanceMatrix, scale4(upperLegWidth, upperLegHeight, upperLegWidth) );
    cizme();
   /*
    gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(instanceMatrix));
    var i =0;
	while( i<6)
	{
	   gl.drawArrays(gl.TRIANGLE_FAN, 4*i, 4);
	   i++;
	}
	*/
	
}

function rightLowerLeg() {

    instanceMatrix = mult(modelViewMatrix, translate(-2.5, 0.5 * lowerLegHeight, 0.0) );
	instanceMatrix = mult(instanceMatrix, scale4(lowerLegWidth, lowerLegHeight, lowerLegWidth) )
    cizme();
	/*
	gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(instanceMatrix));
	var i =0;
	while( i<6)
	{
	   gl.drawArrays(gl.TRIANGLE_FAN, 4*i, 4);
	   i++;
	}
	*/
	
}

function quad(a, b, c, d) 
{	
		colors.push(vertexColors[a]);
		pointsArray.push(vertices[a]);
		colors.push(vertexColors[a]);
		pointsArray.push(vertices[b]);
		//colors.push(vertexColors[a]);
		colors.push(vertexColors[2]);
		pointsArray.push(vertices[c]);
		//colors.push(vertexColors[a]);
		colors.push(vertexColors[2]);
		pointsArray.push(vertices[d]);
}

function cizme()
{
	gl.uniformMatrix4fv(modelViewMatrixLoc, false, flatten(instanceMatrix));
	var i =0;
	while( i<6)
	{
	   gl.drawArrays(gl.TRIANGLE_FAN, 4*i, 4);
	   i++;
	}
}
function cube()
{
    quad( 1, 0, 3, 2 );
    quad( 2, 3, 7, 6 );
    quad( 3, 0, 4, 7 );
    quad( 6, 5, 1, 2 );
    quad( 4, 5, 6, 7 );
    quad( 5, 4, 0, 1 );
}
function colorCube()
{
    quad( 1, 0, 3, 2 );
    quad( 2, 3, 7, 6 );
    quad( 3, 0, 4, 7 );
    quad( 6, 5, 1, 2 );
    quad( 4, 5, 6, 7 );
    quad( 5, 4, 0, 1 );
}

window.onload = function init() {
	
	
	canvas = document.getElementById( "gl-canvas" );

    gl = WebGLUtils.setupWebGL( canvas );
    if ( !gl ) { alert( "WebGL isn't available" ); }

    gl.viewport( 0, 0, canvas.width, canvas.height );
    gl.clearColor( 1.0, 1.0, 1.0, 1.0 );
	gl.enable( gl.DEPTH_TEST );

    //
    //  Load shaders and initialize attribute buffers
    //
    program = initShaders( gl, "vertex-shader", "fragment-shader");

    gl.useProgram( program);
	colorCube();
    instanceMatrix = mat4();

    projectionMatrix = ortho(-10.0,10.0,-10.0, 10.0,-10.0,10.0);
    modelViewMatrix = mat4();


    gl.uniformMatrix4fv(gl.getUniformLocation( program, "modelViewMatrix"), false, flatten(modelViewMatrix) );
    gl.uniformMatrix4fv( gl.getUniformLocation( program, "projectionMatrix"), false, flatten(projectionMatrix) );

    modelViewMatrixLoc = gl.getUniformLocation(program, "modelViewMatrix")

    cube();

    vBuffer = gl.createBuffer();

    gl.bindBuffer( gl.ARRAY_BUFFER, vBuffer );
    gl.bufferData(gl.ARRAY_BUFFER, flatten(pointsArray), gl.STATIC_DRAW);

    var vPosition = gl.getAttribLocation( program, "vPosition" );
    gl.vertexAttribPointer( vPosition, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vPosition );
	
	cBuffer = gl.createBuffer();
    gl.bindBuffer( gl.ARRAY_BUFFER, cBuffer );
    gl.bufferData( gl.ARRAY_BUFFER, flatten(colors), gl.STATIC_DRAW );
	
	var vColor = gl.getAttribLocation( program, "vColor" );
    gl.vertexAttribPointer( vColor, 4, gl.FLOAT, false, 0, 0 );
    gl.enableVertexAttribArray( vColor );
      
	var i=0;
    while( i<numNodes)
	{
		initNodes(i);
		i++;
	}

	
////////aspect ratio///////////////dersde işlenen 5.slayt 36 ıncı sayfadaki kod.
	window.onresize = function()
	{
			var min = innerWidth;
			if (innerHeight < min)
			{
				min = innerHeight;
			}
			if (min < canvas.width || min < canvas.height)
			{
					gl.viewport(0, canvas.height-min, min, min);
			}
	};
/////////////////////////////////

/*function(event) {
	
	if(event.keyCode==100 || event.keyCode==68)
	{
         theta+=1;
	}
       render();
       
    };
*//*var e= new Event('change');
window.addEventListener("keypress", function(event){

if(event.key=="D" || event.key=="d"){
        document.getElementById("slider0").stepUp();
        document.getElementById("slider0").dispatchEvent(e);
    }
    
}
*/
render();
}
var render = function() {

        gl.clear( gl.COLOR_BUFFER_BIT ||gl.DEPTH_BUFFER_BIT );
		
        traverse(torsoId);
        requestAnimFrame(render);
}

window.addEventListener("keypress", function(event){
    if(event.key=="D" || event.key=="d"){
        theta[torsoId2] += 1;
        initNodes(torsoId2);
    }
    else if(event.key=="A" || event.key=="a"){
        theta[torsoId2] -= 1;
        initNodes(torsoId2);
    }
    else if(event.key=="W" || event.key=="w"){
		
        theta[torsoId] += 1;
        initNodes(torsoId);
    }
    else if(event.key=="S" || event.key=="s"){
        theta[torsoId] -= 1;
        initNodes(torsoId);
    }
});