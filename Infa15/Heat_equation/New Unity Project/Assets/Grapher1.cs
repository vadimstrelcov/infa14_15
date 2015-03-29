using UnityEngine; 
public class Grapher1 : MonoBehaviour { 
	private int resolution = 520;
	[Range(0.01f, 0.1f)] 
	public float size = 0.05f;
	public float xLong = 0.8f;
	public float temperature = 0;
	private int index = 0; 
	private GameObject Graph;
	private GameObject Temp; 
	public Vector2 scannedpoint = new Vector2(0.5f,0.5f);
	private int currentResolution; 
	private ParticleSystem.Particle[] points;
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
		}
	void Update () {  
		if (Graph.GetComponent<Grapher2> ().ExperiementOn) {
						if (currentResolution != resolution || points == null) { 
								CreatePoints ();  
						}  
			temperature = (float)Graph.GetComponent<Grapher2> (). GetTemperature (scannedpoint) ;
						Temp.GetComponent<TextMesh> ().text = temperature.ToString ();
						points [index % resolution].position = new Vector2 (xLong, (temperature)/30000f);
						index++;
						for (int i = 0; i < resolution; i++) { 
								Vector3 p = points [i].position; 
								p.x -= Time.deltaTime / 10;
								points [i].position = p; 
								points [i].size = size;
						} 
						particleSystem.SetParticles (points, points.Length); 
				}
	} 
}