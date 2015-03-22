#include "Polygon.h"

template <typename T>
int find(vector<T>* massive, T* A) {
	for (int index=0;index<(int)massive->size();index++) {
		if ((*massive)[index]==(*A)) {
			return index;
		}
	}
	return -1;
}

Polygon::Polygon() {
    //ctor
}

Polygon::Polygon(const char* file_name, const int N_x, const int N_y, const int N_t) {
    FILE* f=fopen(file_name,"rt");
    if (f==NULL) {
        fprintf(stderr,"File \"%s\" does not exist", file_name);
        exit(1);
    } else {

		this->log=1;

		if (this->log) {
			this->file_log=fopen("log.txt","wt");
		}
        /*
			structure of input file:
				physical properties:
					density (ro)
					thermal_conduction (lambda)
					specific_heat (c)
					heat_transfer (a)
					temperature_air
				number of edges
				edge:
					pair of points
					type
					value (boundary condition)
				initial conditions:
					temperature_initial
				maximum time
				number of heat sources and number of events
				event:
					id
					heat source
					coordinates
					start_time
					finish_time
					power
        */
        fscanf(f,"density=%lf thermal_conduction=%lf specific_heat=%lf heat_transfer=%lf temperature_air=%lf\n",&(this->density), &(this->thermal_conduction), &(this->specific_heat), &(this->heat_transfer), &(this->temperature_air));
        fscanf(f,"number_edges=%d\n",&(this->number_edges));
        if (this->log) {
			fprintf(this->file_log,"Physical properties: density=%.1lf thermal_conduction=%.1lf specific_heat=%.1lf heat_transfer=%.1lf temperature_air=%.1lf number_edges=%d\nEdges:\n",
				this->density,
				this->thermal_conduction,
				this->specific_heat,
				this->heat_transfer,
				this->temperature_air,
				this->number_edges);
		}
        for (int index=0;index<number_edges;index++) {
            Point2D first, second;
            double value=0.0;
            char type;
            fscanf(f,"%lf %lf %lf %lf %c", &first.x, &first.y, &second.x, &second.y, &type);
            type-='0';
            if (type<0 || type>2) {
				fprintf(stderr, "Invalid type on %d edge\n",index+1);
				exit(1);
			}
            if (type==0 || type==1) {
				fscanf(f,"%lf",&value);
			}
			fscanf(f,"\n");
            this->vect_edges.push_back(Edge(first, second, type, value));
            if (this->log) {
				fprintf(this->file_log, "(%.3lf;%.3lf)->(%.3lf;%.3lf) %d %.3lf\n",this->vect_edges.back().first.x,this->vect_edges.back().first.y,
					this->vect_edges.back().second.x,this->vect_edges.back().second.y, (int)vect_edges.back().type, vect_edges.back().value);
			}
        }
        //we need to sort all points
        for (int index=0;index<this->number_edges;index++) {
			if (!this->vect_points.empty()) {
				//find vect_edges[index].first & vect_edges[index].second and, if not exist push
				int find_elem;
				if ((find_elem=find(&(this->vect_points),&(this->vect_edges[index].first)))==-1) {
					this->vect_points.push_back(vect_edges[index].first);
				}
				if ((find_elem=find(&(this->vect_points),&(this->vect_edges[index].second)))==-1) {
					this->vect_points.push_back(vect_edges[index].second);
				}
			} else {
				this->vect_points.push_back(this->vect_edges[index].first);
				this->vect_points.push_back(this->vect_edges[index].second);
			}
		}
		if (this->log) {
			fprintf(this->file_log, "Points:\n");
			for (int index=0;index<this->number_edges;index++) {
				fprintf(this->file_log, "(%.3lf;%.3lf)\n",this->vect_points[index].x,this->vect_points[index].y);
			}
		}

		//find max_x, min_x, max_y, min_y;
		this->max_x=-1.0e+100;
		this->max_y=-1.0e+100;
		this->min_x=+1.0e+100;
		this->min_y=+1.0e+100;
		for (int index=0;index<this->number_edges;index++) {
			if (this->vect_points[index].x>this->max_x) {
				this->max_x=this->vect_points[index].x;
			}
			if (this->vect_points[index].x<this->min_x) {
				this->min_x=this->vect_points[index].x;
			}
			if (this->vect_points[index].y>this->max_y) {
				this->max_y=this->vect_points[index].y;
			}
			if (this->vect_points[index].x<this->min_y) {
				this->min_y=this->vect_points[index].y;
			}
		}
		this->n_x=N_x;
		this->n_y=N_y;
		this->h_x=(this->max_x-this->min_x)/n_x;
		this->h_y=(this->max_y-this->min_y)/n_y;
		if (this->log) {
			fprintf(this->file_log, "Grid: min_x=%.3lf min_y=%.3lf max_x=%.3lf max_y=%.3lf (%.3lfx%.3lf)\n",this->min_x, this->min_y, this->max_x, this->max_y, this->max_x-this->min_x, this->max_y-this->min_y);
		}
        //find the leftmost (and if there are several, than find the leftmost and lowest
        int index_left_point=0;
        for (int index=0;index<this->number_edges;index++) {
			if (this->vect_points[index].x==this->vect_points[index_left_point].x) {
				if (this->vect_points[index].y<this->vect_points[index_left_point].y) {
					index_left_point=index;
				}
			} else {
				if (this->vect_points[index].x<this->vect_points[index_left_point].x) {
					index_left_point=index;
				}
			}
		}
		swap(this->vect_points[0],this->vect_points[index_left_point]);
		for (int index1=1;index1<this->number_edges;index1++) {
			//find index of next points for sort all points
			if (index1!=1) {
				for (int index2=0;index2<(int)vect_edges.size();index2++) {
					if (vect_edges[index2].first==(this->vect_points)[index1-1]) {
						if (vect_edges[index2].second!=(this->vect_points)[index1-2]) {
							swap((this->vect_points[index1]),(this->vect_points)[find(&(this->vect_points),&vect_edges[index2].second)]);
						}
					} else {
						if (vect_edges[index2].second==(this->vect_points)[index1-1]) {
							if (vect_edges[index2].first!=(this->vect_points)[index1-2]) {
								swap((this->vect_points)[index1],(this->vect_points)[find(&(this->vect_points),&vect_edges[index2].first)]);
							}
						}
					}
				}
			} else {
				int index_next[2]={-1,-1};
				for (int index2=0;index2<number_edges;index2++) {
					if (this->vect_edges[index2].first==this->vect_points[0]) {
						if (index_next[0]==-1) {
							index_next[0]=find(&(this->vect_points),&(this->vect_edges[index2].second));
						} else {
							index_next[1]=find(&(this->vect_points),&(this->vect_edges[index2].second));
							break;
						}
					} else {
						if (vect_edges[index2].second==this->vect_points[0]) {
							if (index_next[0]==-1) {
								index_next[0]=find(&(this->vect_points),&(this->vect_edges[index2].first));
							} else {
								index_next[1]=find(&(this->vect_points),&(this->vect_edges[index2].first));
								break;
							}
						}
					}
				}
				//create 2 Vectors2D and calculate rotation. if rotation.z>0 then first Vector2D is right, otherwise - wrong
				double rotation=((this->vect_points)[index_next[0]].x-(this->vect_points)[0].x)*((this->vect_points)[index_next[1]].y-(this->vect_points)[0].y)-
					((this->vect_points)[index_next[0]].y-(this->vect_points)[0].y)*((this->vect_points)[index_next[1]].x-(this->vect_points)[0].x);
				if (rotation>0.0) {
					swap(this->vect_points[1],this->vect_points[index_next[0]]);
				} else {
					swap(this->vect_points[1],this->vect_points[index_next[1]]);
				}
			}
		}
		if (this->log) {
			fprintf(this->file_log, "Vect_points after sort:\n");
			for (int index=0;index<this->number_edges;index++) {
				fprintf(this->file_log, "(%.3lf;%.3lf)\n",this->vect_points[index].x, this->vect_points[index].y);
			}
		}
		//sort vect_edges
		for (int index=0;index<this->number_edges-1;index++) {
			for (int tmp_index=index;tmp_index<this->number_edges;tmp_index++) {
				if ( (this->vect_points[index]==this->vect_edges[tmp_index].first &&  this->vect_points[index+1]==this->vect_edges[tmp_index].second) ||
					 (this->vect_points[index]==this->vect_edges[tmp_index].second && this->vect_points[index+1]==this->vect_edges[tmp_index].first) ) {
						swap(this->vect_edges[index], this->vect_edges[tmp_index]);
						break;
				}
			}
		}
		if (this->log) {
			fprintf(this->file_log, "Vect_edges after sort:\n");
			for (int index=0;index<this->number_edges;index++) {
				fprintf(this->file_log, "(%.3lf;%.3lf)->(%.3lf;%.3lf)\n",this->vect_edges[index].first.x, this->vect_edges[index].first.y,
					this->vect_edges[index].second.x, this->vect_edges[index].second.y);
			}
		}


		//we need equation of that lines
        for (int index=0;index<this->number_edges-1;index++) {
			this->vect_lines.push_back(Line(this->vect_points[index], this->vect_points[index+1]));
		}
		this->vect_lines.push_back(Line(this->vect_points[this->number_edges-1], this->vect_points[0]));

		fscanf(f,"temperature_initial=%lf\n",&(this->temperature_initial));

		fscanf(f,"time_max=%lf\n",&(this->time_max));
		this->n_t=N_t;
		this->h_t=this->time_max/N_t;
		if (this->log) {
			fprintf(this->file_log, "Temperature_initial=%lf\n",this->temperature_initial);
			fprintf(this->file_log, "Time_max=%lf\n",this->time_max);
		}

		int number_events;
		fscanf(f,"number_heat_source=%d events=%d",&(this->number_heat_source), &number_events);
		this->vect_heat_source.resize(this->number_heat_source);
		for (int index=0;index<number_events;index++) {
			Heat_Source tmp;
			int id;
			fscanf(f,"%d %lf %lf %lf %lf %lf",&id, &tmp.coord.x, &tmp.coord.y, &tmp.time_start, &tmp.time_finish, &tmp.power);
			this->vect_heat_source[id-1].push_back(tmp);
		}
		if (this->log) {
			for (int i=0;i<this->number_heat_source;i++) {
				if (!this->vect_heat_source[i].empty()) {
					for (int index=0;index<(int)this->vect_heat_source[i].size();index++) {
						fprintf(this->file_log, "id=%d (%.3lf;%.3lf) start=%.1lf finish=%.1lf power=%.1lf\n",i+1,
							this->vect_heat_source[i][index].coord.x,
							this->vect_heat_source[i][index].coord.y,
							this->vect_heat_source[i][index].time_start,
							this->vect_heat_source[i][index].time_finish,
							this->vect_heat_source[i][index].power);
					}
				} else {
					fclose(this->file_log);
					fprintf(stderr, "There aren't %d heat source\n",i+1);
					exit(1);
				}
			}
		} else {
			for (int i=0;i<this->number_heat_source;i++) {
				if (this->vect_heat_source[i].empty()) {
					fprintf(stderr, "There aren't %d heat source\n",i+1);
					exit(1);
				}
			}
		}
		if (this->log) {
			fclose(this->file_log);
		}

		//initial all the rest variable
		this->vect_rectangle.resize(n_y);
		for (int i=0;i<this->n_y;i++) {
			this->vect_rectangle[i].resize(n_x);
			for (int j=0;j<this->n_x;j++) {
				this->vect_rectangle[i][j].status=0;
			}
		}


    }
}

void Polygon::get_partition() {

	if (this->log) {
		this->file_log=fopen("log.txt", "at+");
	}

	vector<vector<char> > vect_is_in_shape;
	vect_is_in_shape.resize(n_y);
	for (int i=0;i<n_y;i++) {
		vect_is_in_shape[i].resize(n_x);
		if (i==0) {
			for (int j=0;j<n_x;j++) {
				vect_is_in_shape[i][j]=0;
			}
		}
	}

	for (int i=0;i<n_y;i++) {
		for (int j=0;j<n_x;j++) {
			Point2D point2d_from=Point2D(this->min_x+j*this->h_x, this->min_y+i*this->h_y);
			Point2D point2d_to=Point2D(this->min_x+j*this->h_x+this->h_x, this->min_y+i*this->h_y+2.0*(this->max_y-this->min_y));
			Line tmp_line(point2d_from, point2d_to);
			while (1) {
				bool flag=1; //suppose that line is correct
				//check: is it parallel?
				for (int index=0;index<this->number_edges;index++) {
					if (fabs(this->vect_lines[index].a*tmp_line.b-this->vect_lines[index].b*tmp_line.a)<epsilon) {
						flag=0;
						//fprintf(this->file_log, "parallel %d\n", index);
						break;
					}
				}
				if (flag) {
					//check: is any vertex on tmp_line?
					for (int index=0;index<this->number_edges;index++) {
						if (fabs(tmp_line.a*this->vect_points[index].x+tmp_line.b*this->vect_points[index].y+
							tmp_line.c)<epsilon && vect_points[index]!=point2d_from) {
								//fprintf(this->file_log, "vertex\n");
								flag=0;
								break;
						}
					}
				}
				//printf("%d %d %d (%lf %lf %lf)\n",i,j,(int)flag, tmp_line.a, tmp_line.b, tmp_line.c);
				if (flag) {
					//calculate ...
					int count=0;
					for (int index=0;index<this->number_edges;index++) {
						Point2D intersection;
						intersection.x=-(this->vect_lines[index].c*tmp_line.b-this->vect_lines[index].b*tmp_line.c)/(this->vect_lines[index].a*tmp_line.b-this->vect_lines[index].b*tmp_line.a);
						intersection.y=-(this->vect_lines[index].a*tmp_line.c-this->vect_lines[index].c*tmp_line.a)/(this->vect_lines[index].a*tmp_line.b-this->vect_lines[index].b*tmp_line.a);
						if (intersection.x-(this->min_x+j*this->h_x)>epsilon) {
							/*
							if (index<number_edges-1) {
								if (intersection.x>=min(this->vect_points[index].x,this->vect_points[index+1].x) &&
									intersection.x<=max(this->vect_points[index].x,this->vect_points[index+1].x) &&
									intersection.y>=min(this->vect_points[index].y,this->vect_points[index+1].y) &&
									intersection.y<=max(this->vect_points[index].y,this->vect_points[index+1].y) ) {
									count++;
								}
							} else {
								if (intersection.x>=min(this->vect_points[index].x,this->vect_points[0].x) &&
									intersection.x<=max(this->vect_points[index].x,this->vect_points[0].x) &&
									intersection.y>=min(this->vect_points[index].y,this->vect_points[0].y) &&
									intersection.y<=max(this->vect_points[index].y,this->vect_points[0].y) ) {
									count++;
								}
							}
							*/

							if (index<number_edges-1) {
								if (intersection.x-min(this->vect_points[index].x,this->vect_points[index+1].x)>=-epsilon &&
									intersection.x-max(this->vect_points[index].x,this->vect_points[index+1].x)<=+epsilon &&
									intersection.y-min(this->vect_points[index].y,this->vect_points[index+1].y)>=-epsilon &&
									intersection.y-max(this->vect_points[index].y,this->vect_points[index+1].y)<=+epsilon ) {
									count++;
								}
							} else {
								if (intersection.x-min(this->vect_points[index].x,this->vect_points[0].x)>=-epsilon &&
									intersection.x-max(this->vect_points[index].x,this->vect_points[0].x)<=+epsilon &&
									intersection.y-min(this->vect_points[index].y,this->vect_points[0].y)>=-epsilon &&
									intersection.y-max(this->vect_points[index].y,this->vect_points[0].y)<=+epsilon ) {
									count++;
								}
							}

						}
					}
					//fprintf(this->file_log, "%d %d %d\n",i,j,count);
					vect_is_in_shape[i][j]=count%2;
					break;
				} else {
					point2d_to.x+=this->h_x;
					tmp_line=Line(point2d_from,point2d_to);
				}
			}
		}
	}

	for (int i=0;i<n_y;i++) {
		for (int j=0;j<n_x;j++) {
			if (i<n_y-1) {
				if (j<n_x-1) {
					this->vect_rectangle[i][j].status=((vect_is_in_shape[i][j]) || (vect_is_in_shape[i][j+1] && j<n_x-1) ||
								  (vect_is_in_shape[i+1][j] && i<n_y-1) || (vect_is_in_shape[i+1][j+1] && i<n_y-1 && j<n_x-1)) ? 2 : 0;
				} else {
					this->vect_rectangle[i][j].status=((vect_is_in_shape[i][j]) || (vect_is_in_shape[i+1][j])) ? 2 : 0;
				}
			} else {
				if (j<n_x-1) {
					this->vect_rectangle[i][j].status=((vect_is_in_shape[i][j]) || (vect_is_in_shape[i][j+1])) ? 2 : 0;
				} else {
					this->vect_rectangle[i][j].status=0;
				}
			}
		}
	}

	for (int i=0;i<n_y;i++) {
		for (int j=0;j<n_x;j++) {
			if (this->vect_rectangle[i][j].status==2) {
				if (i==0 || j==0 || i==n_y-1 || j==n_x-1) {
					this->vect_rectangle[i][j].status=1;
				} else {
					if (i<n_y-1 && j<n_x-1) {
						if (vect_rectangle[i-1][j].status==0 || vect_rectangle[i+1][j].status==0 ||
							vect_rectangle[i][j-1].status==0 || vect_rectangle[i][j+1].status==0) {
							vect_rectangle[i][j].status=1;
						}
					}
				}
			}
		}
	}

	if (this->log) {
		fprintf(this->file_log, "Status:\n");
		for (int i=n_y-1;i>=0;i--) {
			for (int j=0;j<n_x;j++) {
				fprintf(this->file_log, "%d ", this->vect_rectangle[i][j].status);
			}
			fprintf(this->file_log, "\n");
		}
	}

	for (int i=0;i<n_y;i++) {
		for (int j=0;j<n_x;j++) {
			if (this->vect_rectangle[i][j].status==1) {
				double minl=1.0e+100;
				int index=0;
				for (int k=0;k<this->number_edges;k++) {
					Point2D D(this->min_x+j*this->h_x, this->min_y+j*this->h_y);
					double tmp_length=fabs(this->vect_lines[k].a*D.x+this->vect_lines[k].b*D.y+this->vect_lines[k].c)/(this->vect_lines[k].a*this->vect_lines[k].a+this->vect_lines[k].b*this->vect_lines[k].b);
					if (minl-tmp_length>-epsilon) {
						index=k;
						minl=tmp_length;
					}
				}
				this->vect_rectangle[i][j].type=this->vect_edges[index].type;
				this->vect_rectangle[i][j].value=this->vect_edges[index].value;
			}
		}
	}

	if (this->log) {
		fprintf(this->file_log, "Type:\n");
		for (int i=n_y-1;i>=0;i--) {
			for (int j=0;j<n_x;j++) {
				if (this->vect_rectangle[i][j].status==1) {
					fprintf(this->file_log, "%d ",(int)this->vect_rectangle[i][j].type);
				} else {
					fprintf(this->file_log, "9 ");
				}
			}
			fprintf(this->file_log, "\n");
		}
	}

	if (this->log) {
		fprintf(this->file_log, "Value:\n");
		for (int i=n_y-1;i>=0;i--) {
			for (int j=0;j<n_x;j++) {
				if (this->vect_rectangle[i][j].status==1 && this->vect_rectangle[i][j].type!=2) {
					fprintf(this->file_log, "%.1lf ",this->vect_rectangle[i][j].value);
				} else {
					fprintf(this->file_log, "999 ");
				}
			}
			fprintf(this->file_log, "\n");
		}
	}
}

void get_tmp_solve(vector<vector<double> >* A, vector<vector<double> >* B, bool flag) {

}

void Polygon::solve() {
	vector<vector<double> > U;
	U.resize(this->n_y);
	for (int i=0;i<n_y;i++) {
		U[i].resize(this->n_x);
		for (int j=0;j<n_x;j++) {
			U[i][j]=this->temperature_initial;
		}
	}
	for (int tau=0;tau<this->n_t;tau++) {
        vector<vector<double> > U1, U2;
        U1.resize(this->n_y);
        U2.resize(this->n_y);
        for (int i=0;i<n_y;i++) {
			U1[i].resize(this->n_x);
			U2[i].resize(this->n_x);
			for (int j=0;j<n_x;j++) {
				U1[i][j]=U[i][j];
			}
		}
		get_tmp_solve(&U1,&U2,0);
		for (int i=0;i<this->n_y;i++) {
			for (int j=0;j<this->n_x;j++) {
				U1[i][j]=U2[i][j];
			}
		}
		get_tmp_solve(&U1,&U2,1);
		for (int i=0;i<this->n_y;i++) {
			for (int j=0;j<this->n_x;j++) {
				U[i][j]=U2[i][j];
			}
		}
	}
}
