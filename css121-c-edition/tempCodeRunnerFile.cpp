double AvrScore(Student student[],int size){
    double avr_score = 0;
    for(int i=0; i<size; i++){
        avr_score+=student[i].score;
    }
    return avr_score/size;
}