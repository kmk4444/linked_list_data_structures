struct nodeClass
{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent
{
	int studentID;
	int midterm;
	struct nodeStudent *next;
};


// You must write all the function definitions to be used in this lab into this file.
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.

void insert(struct nodeClass **head, int id, int midterm){
    struct nodeClass *birinciSinif, *ikinciSinif,*ucuncuSinif, *dorduncuSinif, *secilenSinif;
    struct nodeStudent *students;
    struct nodeStudent *newStudent;
    if(!(*head)){
        //Eğer liste hiç başlatılmadı ise 4 sınıf içinde burada liste oluştuacağız

        //İlk sınıf 1. sınıf
        *head = (struct nodeClass *) malloc(sizeof(struct nodeClass) *1);
        (*head)->classID = 1;
        (*head)->classMidtermAverage = 0.0;
        (*head)->next = NULL;
        (*head)->studentPtr = NULL;

         //2. sınıf
        (*head)->next = (struct nodeClass *) malloc(sizeof(struct nodeClass) *1);
        ikinciSinif = (*head)->next;
        ikinciSinif->classID = 2;
        ikinciSinif->classMidtermAverage = 0.0;
        ikinciSinif->next = NULL;
        ikinciSinif->studentPtr = NULL;

        //3. sınıf
        ikinciSinif->next = (struct nodeClass *) malloc(sizeof(struct nodeClass) *1);
        ucuncuSinif = ikinciSinif->next;
        ucuncuSinif->classID = 3;
        ucuncuSinif->classMidtermAverage = 0.0;
        ucuncuSinif->next = NULL;
        ucuncuSinif->studentPtr = NULL;


        //4. sınıf
        ucuncuSinif->next = (struct nodeClass *) malloc(sizeof(struct nodeClass) *1);
        dorduncuSinif = ucuncuSinif->next;
        dorduncuSinif->classID = 4;
        dorduncuSinif->classMidtermAverage = 0.0;
        dorduncuSinif->next = NULL;
        dorduncuSinif->studentPtr = NULL;

    }
//    printf("Tum siniflar basari ile olusturuldu\n");

    birinciSinif = *head;
    ikinciSinif = birinciSinif->next;
    ucuncuSinif = ikinciSinif->next;
    dorduncuSinif = ucuncuSinif->next;
    int isFirstStudent = 0;

    if(id / 1000 == 66)// birinci sinif
    {
        secilenSinif = birinciSinif;
        if(!birinciSinif->studentPtr)
        {
            isFirstStudent = 1;
            birinciSinif->studentPtr = (struct nodeStudent *) malloc(sizeof(struct nodeStudent) * 1);
            birinciSinif->studentPtr->midterm = midterm;
            birinciSinif->studentPtr->studentID = id;
            birinciSinif->studentPtr->next = NULL;

        }
        else
            students =  birinciSinif->studentPtr;

    }
    else if(id / 1000 == 77)// ikinci sinif
    {
        secilenSinif = ikinciSinif;
        if(!ikinciSinif->studentPtr)
        {
            isFirstStudent = 1;
            ikinciSinif->studentPtr = (struct nodeStudent *) malloc(sizeof(struct nodeStudent) * 1);
            ikinciSinif->studentPtr->midterm = midterm;
            ikinciSinif->studentPtr->studentID = id;
            ikinciSinif->studentPtr->next = NULL;

        }
        students =  ikinciSinif->studentPtr;
    }
    else if(id / 1000 == 88)// üçüncü sinif
    {
        secilenSinif = ucuncuSinif;
        if(!ucuncuSinif->studentPtr)
        {
            isFirstStudent = 1;
            ucuncuSinif->studentPtr = (struct nodeStudent *) malloc(sizeof(struct nodeStudent) * 1);
            ucuncuSinif->studentPtr->midterm = midterm;
            ucuncuSinif->studentPtr->studentID = id;
            ucuncuSinif->studentPtr->next = NULL;

        }
        students =  ucuncuSinif->studentPtr;
    }
    else if(id / 1000 == 99)// dördüncü sinif
    {
        secilenSinif = dorduncuSinif;
        if(!dorduncuSinif->studentPtr)
        {
            isFirstStudent = 1;
            dorduncuSinif->studentPtr = (struct nodeStudent *) malloc(sizeof(struct nodeStudent) * 1);
            dorduncuSinif->studentPtr->midterm = midterm;
            dorduncuSinif->studentPtr->studentID = id;
            dorduncuSinif->studentPtr->next = NULL;

        }
        students =  dorduncuSinif->studentPtr;
    }
//    printf("Student list address was get successfully\n");

    // Su ana kadar ilgli sınıf bulundu ve artık midterme sonucuna göre ekleme yapacağız
    if(isFirstStudent == 0){
        if(!students->next || secilenSinif->studentPtr->midterm < midterm){
            //listede tek öğrenci var
            if(midterm > students->midterm ){
                newStudent = secilenSinif->studentPtr;
                secilenSinif->studentPtr = (struct nodeStudent *) malloc(sizeof(struct nodeStudent) * 1);
                secilenSinif->studentPtr->midterm = midterm;
                secilenSinif->studentPtr->studentID = id;
                secilenSinif->studentPtr->next = newStudent;

            }else {
                students->next = (struct nodeStudent *) malloc(sizeof(struct nodeStudent) * 1);
                students->next->midterm = midterm;
                students->next->studentID = id;
                students->next->next = NULL;
            }

        }
        else
        {//listede birden fazla öğrenci var
            while(students->next && students->next->midterm > midterm){
                students = students->next;
            }

            newStudent = (struct nodeStudent *) malloc(sizeof(struct nodeStudent) * 1);
            newStudent->midterm = midterm;
            newStudent->studentID = id;
            newStudent->next = students->next;
            students->next = newStudent;
        }

    }
}

void computeClassAverage(struct nodeClass *head){
    struct nodeClass *itr = head;
    struct nodeStudent *itrStudent;
    int numberOfStudents;
    double sum;
    while(itr){
            //printf("%d %lf\n", itr->classID, itr->classMidtermAverage);
            itrStudent = itr->studentPtr;

            sum = 0.0;
            numberOfStudents = 0;

            while(itrStudent){
                //printf("%d %lf\n", itrStudent->studentID, itrStudent->midterm);
                sum += itrStudent->midterm;
                numberOfStudents++;
                itrStudent = itrStudent->next;
            }
            itr->classMidtermAverage = sum / numberOfStudents;

        itr = itr->next;
    }

}

void printAll(struct nodeClass *head){
    struct nodeClass *itr = head;
    struct nodeStudent *itrStudent;
    while(itr){
            printf("%d %.2lf\n", itr->classID, itr->classMidtermAverage);
            itrStudent = itr->studentPtr;
            while(itrStudent){
                printf("%d %d\n", itrStudent->studentID, itrStudent->midterm);
                itrStudent = itrStudent->next;
            }

        itr = itr->next;
    }

}

