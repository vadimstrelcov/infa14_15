using UnityEngine; 
public class Grapher1 : MonoBehaviour { 
	private int resolution = 250;
	[Range(0.01f, 0.1f)] 
	private float size = 0.01f;
	public float xLong = 0.8f;
	public float temperature = 0;
	public float Tmax, Tmin;
	private int index = 0; 
	private GameObject Graph;
	private GameObject Temp; 
	public Vector2 scannedpoint = new Vector2(0.5f,0.5f);
	private int currentResolution; 
	private ParticleSystem.Particle[] points;
	private float []T;
	private void CreatePoints () { 
		currentResolution = resolution;  
		float increment = xLong / (resolution - 1); 
		for(int i = 0; i < resolution; i++){ 
			float x = i * increment; 
			//points[i].position = new Vector3(x, 0f, 0f); 
			points[i].color = new Color(x, 0f, 0f); 
			points[i].size = size; 
		} 
	}  
	void Awake(){
		points = new ParticleSystem.Particle[resolution  ]; 
				for (int i = 0; i < resolution; i++) { 
						points [i].position = new Vector2((float)i/2/resolution+0.5f,-5f); 
						points [i].size = size;
				} 
		Graph = (GameObject.Find ("/Main Camera/Graph 1"));
		Temp = (GameObject.Find ("Temperature")); 
		T = new float[250];
		}
	void Update () {  
		if (Graph.GetComponent<Grapher2> ().ExperiementOn) {
						if (currentResolution != resolution || points == null) { 
								CreatePoints ();  
						} 
			Tmax = Graph.GetComponent<Grapher2>().Tmax;
			Tmin = Graph.GetComponent<Grapher2>().Tmin;
			temperature = (float)Graph.GetComponent<Grapher2> (). GetTemperature (scannedpoint) ;
			Temp.GetComponent<TextMesh> ().text = temperature.ToString ();
			points [index % resolution].position = new Vector2 (xLong,0f);
			T[index%resolution] = temperature;
				index++;
						for (int i = 0; i < resolution; i++) { 
								Vector3 p = points [i].position; 
								p.x -= 1f / 300f;
								p.y  = (T[i]-Tmin)/(Tmax-Tmin)*0.35f;
								points [i].position = p;  
						} 
						particleSystem.SetParticles (points, points.Length); 
				}
	} 
}