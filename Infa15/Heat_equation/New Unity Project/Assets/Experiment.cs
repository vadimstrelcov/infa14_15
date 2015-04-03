using UnityEngine;
using System.Collections;

public class Experiment : MonoBehaviour {
	public Texture2D A; 
	// Use this for initialization
	void Start () { 
		A = new Texture2D(5, 1);
		Color c = new Color (0f,0f,0f);
		for (int i = 0; i<5; i++){
			switch(i)
			{
			case 0: c = new Color (0f,0f,1f);
					break;
			case 1: c = new Color (0f,1f,1f);
					break;
			case 2: c = new Color (0f,1f,0f);
					break;
			case 3: c = new Color (1f,1f,0f);
					break;
			case 4: c = new Color (1f,0f,0f);
					break;
			}
			A.SetPixel(i,0,c);
		}
		A.filterMode = FilterMode.Bilinear;
		A.Apply ();
		Rect R = new Rect (0, 0, A.width, A.height);
		Vector2 V = new  Vector2 (0f, 0f);
		GetComponent<SpriteRenderer>().sprite =  Sprite.Create(A,  R , V );
	}
	
	// Update is called once per frame
	void Update () {
	
	}
}
