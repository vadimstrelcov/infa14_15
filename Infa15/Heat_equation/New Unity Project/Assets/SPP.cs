using UnityEngine;
using System;
using System.Collections;

public class SPP : MonoBehaviour {
	public string x = "000000000";
	public string y = "000000000";
	public float xk=1;
	public float yk=1; 
	private Vector2 Graph;
	private Vector2 aaaa;
	private Vector2 aaab;
	GameObject Graph2;
	GameObject Point;
	void Start() {
		Graph = (GameObject.Find ("/Main Camera/Graph 1")).transform.position;
		Point = (GameObject.Find ("/Main Camera/scanned_point"));
		Graph2 = (GameObject.Find ("/Main Camera/Graph 2"));
		
		aaaa = Camera.main.WorldToScreenPoint(new Vector2(1.2f,0.27f));
		aaab = Camera.main.WorldToScreenPoint(new Vector2(1.2f,0.27f+0.075f));
	}
	void OnGUI() {
				y = GUI.TextField (new Rect (aaaa.x, aaab.y, 100, 20), y, 15);
				x = GUI.TextField (new Rect (aaaa.x, aaaa.y, 100, 20), x, 15);
		}
	void Update()
	{
		float X = Convert.ToSingle (x);
		float Y = Convert.ToSingle (y);
		if (X <= Graph.x + 1 && X >= Graph.x && Y >= Graph.y && Y <= Graph.y + 1) {
						Point.transform.position 
			= new Vector2 (X/xk, Y/yk);
				}
		Graph2.GetComponent<Grapher1>().scannedpoint = new Vector2 (X/xk, Y/yk);
	}
}