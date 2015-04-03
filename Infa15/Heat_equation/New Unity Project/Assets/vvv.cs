using UnityEngine;
using System.Collections;

public class vvv : MonoBehaviour {
	private float Tmax =0 ,Tmin=0;
	private GameObject Graph;
	// Use this for initialization
	void Start () {
		Graph = (GameObject.Find ("/Main Camera/Graph 1"));
	}
	
	// Update is called once per frame
	void Update () {
		Tmax = Graph.GetComponent<Grapher2> ().Tmax;
		Tmin = Graph.GetComponent<Grapher2> ().Tmin;
		GetComponent<TextMesh> ().text = "Tmax = " + Tmax.ToString() + "\n" + "Tmin = " + Tmin.ToString();
	}
}
