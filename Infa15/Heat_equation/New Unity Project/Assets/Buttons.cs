using UnityEngine;
using System.Collections;

public class Buttons : MonoBehaviour {
	public float Width=80;
	public float Height=30;
	[Range(1, 100)] 
	public float x = 55;
	[Range(1, 100)] 
	public float y = 25;
		void OnGUI()
		{
		float buttonWidth = Width;
		float buttonHeight = Height;
			
			// Determine the button's place on screen
			// Center in X, 2/3 of the height in Y
			Rect buttonStart = new Rect(
				Screen.width*x/100f - (buttonWidth / 2),
				Screen.height*y/100f - (buttonHeight / 2),
				buttonWidth,
				buttonHeight
				);
			
			// Draw a button to start the game
		if(GUI.Button(buttonStart,"Start"))
			{
			(GameObject.Find ("/Main Camera/Graph 1")).GetComponent<Grapher2>().ExperiementOn = true;
			}
		Rect buttonPause = new Rect(
			Screen.width*x/100f + (buttonWidth),
			Screen.height*y/100f - (buttonHeight / 2),
			buttonWidth,
			buttonHeight
			);
		
		// Draw a button to pause the game
		if(GUI.Button(buttonPause,"Pause"))
		{
			(GameObject.Find ("/Main Camera/Graph 1")).GetComponent<Grapher2>().ExperiementOn = false;
		}/*
		Rect buttonStop = new Rect(
			Screen.width*x/100f + 2.5f*(buttonWidth),
			Screen.height*y/100f - (buttonHeight / 2),
			buttonWidth,
			buttonHeight
			);*/
		/*
		// Draw a button to stop the game
		if(GUI.Button(buttonStop,"Stop"))
		{
			(GameObject.Find ("/Main Camera/Graph 1")).GetComponent<Grapher2>().ExperiementOn = false;
			(GameObject.Find ("/Main Camera/Graph 1")).GetComponent<Timer>().myTimer = 0;
			//Drop calculations
		}*/
		}

}
