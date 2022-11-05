#ifndef RADIOGRAPHIE_H
#define RADIOGRAPHIE_H

#include <string>
#include <iostream>
#include "patient.h"
#include "cliche.h"
#include "resultatMedecin.h"
#include "resultatPatient.h"

using namespace std;

class Radiographie{

    private:
        int num_examen;
        string type;

        Patient *patient;   //pointeur car aggrégation
        
        string id_medecin;
        string date;
        bool state;
        
        MedecinResult *med_result;
        PatientResult *pat_result;

    public:
        Radiographie(int num_exam, string type, Patient *id_patient,string id_med, string date, bool state){
            this->num_examen = num_exam;
            this->type = type;

            this->patient = id_patient;

            this->id_medecin = id_med;
            this->date = date;
            this->state = state;

            this->med_result = NULL;    //NULL car pas forcément de compte rendu si la radio est pas encore faite
            this->pat_result = NULL;
        };
        
        //Constructeur de recopie
        Radiographie(const Radiographie &r){
            this->num_examen = r.num_examen;
            this->type = r.type;
            this->patient = r.patient;
            this->id_medecin = r.id_medecin;
            this->date = r.date;
            this->state = r.state;
            this->med_result = r.med_result;
            this->pat_result = r.pat_result;
        };

        int get_num_exam(){
            return this->num_examen;
        };
        void set_num_exam(int num){
            this->num_examen = num;
        };


        void get_type(){
            cout << "Radiography type : "<<this->type<<endl;
        };
        void set_type(string type){
            this->type = type;
        };


        void get_patient(){
            this->patient->utilisateur_display();
            this->patient->patient_display();
        }
        void set_patient(Patient *patient){
            this->patient = patient;
        }


        void get_id_medecin(){
            cout << "Medecin ID : "<<this->id_medecin<<endl;
        };
        void set_id_medecin(int id){
            this->id_medecin = id;
        };


        void get_date(){
            cout << "Radiography date : "<<this->date<<endl;
        };
        void set_date(int date){
            this->date = date;
        };


        void get_state(){
            if (this->state){
                cout << "State : radiography is performed"<<endl;
            }else{
                cout << "State : radiography is planned"<<endl;
            };
        };
        void set_state(bool state){
            this->state= state;
        };


        void get_med_result(){
            this->med_result->medecin_result_display();
        }
        void set_med_result(MedecinResult *med){
            this->med_result = med;
        }


        void get_pat_result(){
            this->pat_result->patient_result_display();
        }
        void set_pat_result(PatientResult *pat){
            this->pat_result = pat;
        }


        void radiographie_display();
};

#endif