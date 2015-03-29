using UnityEngine;
using System.Collections;

public class Text : MonoBehaviour {
	[Range(1, 100)] 
	public float x = 50;
	[Range(1, 100)] 
	public float y = 95;
	void Update () {
		Vector2 p = Camera.main.ScreenToWorldPoint(new Vector2 (Screen.width*x/100f,Screen.height*y/100f));
		transform.position = p;
	}
}
