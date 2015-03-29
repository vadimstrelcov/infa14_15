using UnityEngine;
using System.Collections;

public class Timer : MonoBehaviour {

	public float myTimer = 0; 
	public float delta=0;
	// Update is called once per frame
	void Update () {
		 myTimer += delta;
		//(GameObject.Find ("/Render/Main Camera/HP/HPE")).GetComponent<TextMesh>().text = ar;
		transform.GetComponent<TextMesh> ().text = myTimer.ToString();
	}
}
