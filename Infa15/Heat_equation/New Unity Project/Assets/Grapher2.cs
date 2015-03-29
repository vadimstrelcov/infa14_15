﻿using UnityEngine;
using System.Collections;
using System;
using System.Runtime.InteropServices;
public class Grapher2 : MonoBehaviour { 
	[DllImport ("1" )] 
	private static extern void Create_polygon( int aa,int log_, int N_x, int N_y, double N_t);
	[DllImport ("1" )] 
	private static extern void Get_partition ();
	[DllImport ("1" )] 
	private static extern double Get_length(); 
	[DllImport ("1" )] 
	private static extern double Get_height ();
	[DllImport ("1" )] 
	private static extern int Get_x ();
	[DllImport ("1" )] 
	private static extern int Get_y ();
	[DllImport ("1" )] 
	private unsafe static extern void Solve(int NT,double * Temp);
	[DllImport ("1" )] 
	private static extern double Get_Temp_By_ij( int i,  int j);
	[DllImport ("1" )] 
	private static extern double Get_Temp_By_xy( double x,  double y);
	public int nx = 1,ny = 1;
	public int q1=2;
	public int q2=2;
	public int resx,resy;
	private float SMALL_TIME_STEP =  0.0001f;  
	private GameObject CLOCK;  
	private int Time_steps = 5;

	
	public bool ExperiementOn = false;
	[Range(10, 100)] 
	public int resolutionx = 70; 
	[Range(10, 100)] 
	public int resolutiony = 70; 
	[Range(0.01f, 0.1f)] 
	public float size = 0.05f; 
	public float xk=1;
	public float yk=1;
	private GameObject SPP;
	private GameObject Point;
	private GameObject Graph2;
	private Vector2 Graph;
	private int currentResolutionx;
	private int currentResolutiony;
	public Vector2 scannedpoint = new Vector2(0.5f,0.5f); 
	private ParticleSystem.Particle[] points;
	private double []TT; 
	private void CreatePoints () {
		currentResolutiony = resolutiony;
		currentResolutionx = resolutionx;
		points = new ParticleSystem.Particle[resolutionx * resolutiony]; 
		float incrementx = 1f / (resolutionx - 1); 
		float incrementy = 1f / (resolutiony - 1); 
		int i = 0;  
		for (int y = 0; y < resolutiony; y++) { 
			for (int x = 0; x < resolutionx; x++) { 
				Vector3 p = new Vector3(x * incrementx, y * incrementy ,0f); 
				points[i].position = p; 
				points[i].color = new Color(0f, 0f, 0f); 
				points[i++].size = size; 
			} 
		} 
	}  
	void Start(){
		GameObject Graph12 = (GameObject.Find ("/Main Camera/Graph 1"));
		CLOCK = (GameObject.Find ("TimeTrue"));
		Create_polygon (5, 1, 100, 100, (double)SMALL_TIME_STEP);
		Debug.Log("Fu ");
		Get_partition ();
		Debug.Log("Fu 2");
		nx = Get_x ();
		ny = Get_y (); 
		TT  = new double[nx*ny]; 
		if (nx <= 100) {
			Graph12.GetComponent<Grapher2> ().resolutionx = nx;
			resx = nx;
			q1=1;
		}
		else {
			q1 = nx/80;
			resx = nx/++q1;
			Graph12.GetComponent<Grapher2> ().resolutionx = resx;
		}
		if (ny <= 100){
			Graph12.GetComponent<Grapher2> ().resolutiony = ny;
			resy = ny;
			q2=1;
		}
		else {
			q2 = ny/80;
			resy = ny/++q2;
			Graph12.GetComponent<Grapher2> ().resolutiony = resy;
		}
		Graph12.GetComponent<Grapher2> ().xk = (float)Get_length ();
		Graph12.GetComponent<Grapher2> ().yk = (float)Get_height ();
		(GameObject.Find ("SPP")).GetComponent<SPP>().xk=(float)Get_length ();
		(GameObject.Find ("SPP")).GetComponent<SPP>().yk=(float)Get_height ();
		
		
		SPP = (GameObject.Find ("SPP"));
		Point = (GameObject.Find ("/Main Camera/scanned_point"));
		Graph2 = (GameObject.Find ("/Main Camera/Graph 2"));
		Graph = (GameObject.Find ("/Main Camera/Graph 1")).transform.position;
		}
	public float GetTemperature(Vector2 point)
	{
		return (float)Get_Temp_By_xy((double)(point.x*xk),(double)(point.y*yk));
	}
	void Update () { 
		if (currentResolutionx != resolutionx ||currentResolutiony != resolutiony || points == null) { 
			CreatePoints(); 
		} 

		if (Input.GetButton("Fire1")) {
			Vector2 mouse =  Camera.main.ScreenToWorldPoint(Input.mousePosition);
			if(mouse.x<=Graph.x+1 && mouse.x>=Graph.x && mouse.y>=Graph.y && mouse.y<=Graph.y+1) {
				scannedpoint = mouse;
				Point.transform.position = scannedpoint;
				Graph2.GetComponent<Grapher1>().scannedpoint = scannedpoint;
				SPP.GetComponent<SPP>().x = ((scannedpoint.x)*xk).ToString();
				SPP.GetComponent<SPP>().y = ((scannedpoint.y)*yk).ToString();
					}
				}
		if (ExperiementOn) { 
			int i;
			unsafe {
			fixed(double* qwe = &(TT[0])){
						Solve (Time_steps,qwe);
						CLOCK.GetComponent<Timer> ().delta = SMALL_TIME_STEP * Time_steps;
						for (i = 0; i < points.Length; i++) { 
							float Temp = (float)(*(qwe+i*8));
							if (Temp > 0) points [i].color = RGBfromTemp (Temp); 
							points [i].size = size;
							}
				}
			}
						particleSystem.SetParticles (points, points.Length); 
				}
	}
	Color RGBfromTemp(float T){ 
		float R, G, B;
		R = 0; G = 0; B = 0;
		if (T < 150)
			R = 1f / 150f;
		if (T >= 150 && T<=320)
			R = 1f ;
		if (T > 320 && T<550)
			R = 1f -1f/230f*(T-320);
		if (T >= 550)
			R = 0f;

		if (T < 150)
			G = 0f;
		if (T >= 150 && T<=320)
			G = 1f/170f*(T-150);
		if (T > 320 && T<550)
			G = 1f -1f/230f*(T-320);
		if (T >= 550)
			G = 0f;

		if (T < 150)
			B = 0f;
		if (T >= 150 && T<=320)
			B = 0f;
		if (T > 320 && T<550)
			B = 0f;
		if (T >= 550)
			B = 1f/200f*(T-550);
		return new Color (R,G,B);
	}
}