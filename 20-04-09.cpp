#include <iostream>
#include <iomanip>
using namespace std;
// questa procedura legge da tastiera il numero delle righe e quello delle colonne della matrice ed esegue gli opportuni
// controlli sui valori inseriti
void leggi_righe_colonne(int& r, int& c)
{
do{cout << "Scrivi il numero di righe della matrice (immetti un valore compreso tra 1 e 5): ";
cin >> r;
}
while (r>5);// non può andare al di sopra di 5
do {cout << "Scrivi il numero di colonne della matrice (immetti un valore compreso tra 1 e 5):";
cin >> c;
}
while (c>5);// non può andare al di sopra di 5
}
// questa procedura legge da tastiera i valori della matrice per riga
void leggi_matrice(int r, int c, int m[][5])
{
cout << "inserisci gli elementi della matrice" << endl;
	for (int i=0;i<r;i++) { 
		for (int j=0;j<c;j++)
	{cout << "m[" << i << "][" << j << "]=";
		cin >> m[i][j]; // inserisco i valori della matrice
		}	
	}
}
// questa procedura valuta se la matrice data è Triangolare alta o bassa o se è Diagonale o Identita
void valuta_matrice(int r, int c, int m[][5])
{
// matrice diagonale 
/*da Wikipedia: In matematica, una matrice diagonale è una matrice quadrata in cui solamente i valori della diagonale principale possono essere diversi da 0.
Non si impone che i valori sulla diagonale siano diversi da zero: la matrice quadrata nulla è quindi diagonale. */
	int f,j=0;
	bool t=true;
	for (int i=0;i<r;i++)
	{
		f=i; //assegno ad f il valore di i,perchè così vado a valutare gli elementi sulla diagonale
		j=0;
 while (t && j<c)
		{
		if (j==f) //quando j è uguale a f, mi trovo sulla diagonale 
		{
			if (m[i][f]==0||m[i][f]!=0) //verifico se l'elemento sulla diagonale è uguale o diverso da 0
			{
				t=true;
			}
		}
		else 
			{if (m[i][j]==0) { // se gli altri elementi sono uguali a zero, significa che è diagonale
				t=true;
	}
			else t=false; //se gli elementi sono diversi da zero,significa che non è diagonale
			}
	j++;					
		}
	}
	if (t) cout << "matrice diagonale" << endl;
// matrice triangolare superiore
/*da Wikipedia:Si dice invece matrice triangolare superiore una matrice quadrata con nulli gli elementi al di sotto della diagonale principale */
bool d=true;
f=0;
int o=0;
for (int i=0;i<r;i++)
{
	f=i; //assegno ad f il valore di i,perchè così vado a valutare gli elementi sulla diagonale
	o=i; //assegno ad o il valore di i,perchè così vado a valutare gli elementi sulla diagonale
	while(d && o<r-1) // r meno 1 perchè l'ultimo elemento della riga sarà l'ultimo elemento della diagonale, e quindi non avrà elementi successivi
	{
	if (m[o+1][f]==0) // controllo se gli elementi al di sotto della diagonale sono uguali da zero
	{
		d=true;
	
	}
	else 
	{
		d=false; //se almeno un elemento è diverso di zero, si ferma il ciclo 
	}
		o++;
	}
}
if (d) cout << "matrice triangolare superiorie" << endl;
// matrice triangolare inferiore
/*da Wikipedia: Le matrici triangolari inferiori sono matrici quadrate che hanno nulli tutti gli elementi al di sopra della diagonale principale*/
bool po=true;
f=0;
for (int i=0;i<r;i++)
{
	f=i; //assegno ad f il valore di i,perchè così vado a valutare gli elementi sulla diagonale
	while (po &&f<c-1) // c meno 1 perchè l'ultimo elemento della colonna sarà l'ultimo elemento della diagonale, e quindi non avrà elementi successivi
	{
		if (m[i][f+1]==0) //controlle se gli elementi nella colonna successiva sono uguali a zero
		{
			po=true;
		}
		else {
			po=false; //se almeno un elemento è diverso di zero, si ferma il ciclo 
		}
		f++;
	}
}
if (po) cout << "matrice triangolare inferiore" << endl;
//matrie identitta'
/* In matematica, la matrice identità, anche detta matrice identica o matrice unità, è
 una matrice quadrata in cui tutti gli elementi della diagonale principale sono costituiti dal numero 1, mentre i restanti elementi sono 0.*/
f=0;j=0;
	bool per=true;
	for (int i=0;i<r;i++)
	{
		f=i;//assegno ad f il valore di i,perchè così vado a valutare gli elementi sulla diagonale
		j=0;
 while (per && j<c)
		{
		if (j==f) //quando j è uguale a f, mi trovo sulla diagonale 
		{
			if (m[i][f]==1) //se il valore della diagonale è uguale a 1, è una matrice identita'
			{
				per=true;
			}
		}
		else 
			{if (m[i][j]==0) { //se gli altri elementi sono uguali a zero, significa che è identita'
				per=true;
	}
			else per=false; //se gli elementi sono diversi da zero,significa che non è identita'
			}
	j++;					
		}
	}
	if (per) cout << "Matrice identita'" << endl;
	if (per && po && d && t) cout << "La matrice non ha caratteristiche particolari" << endl;
}
// questa procedura stampa a video la matrice originale e quella Trasposta da essa ottenuta
void trasposta(int r, int c, int m[][5])
{
	/*In matematica, la matrice trasposta di una matrice è la matrice ottenuta scambiandone le righe con le colonne. */
	int temp[c][r];
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			temp[j][i]=m[i][j]; //scambia riga e colonna 
		}
	}
	cout << "La Matrice originale: " << endl;
for (int i=0;i<r;i++)
{
	for (int j=0;j<c;j++)
	{
		cout << m[i][j] << " ";
	}
	cout << endl;
 }
 cout << "La matrice trasposta: " << endl;
 for (int i=0;i<c;i++)
{
	for (int j=0;j<r;j++)
	{
		cout << temp[i][j] << " ";
	}
	cout << endl;
 } 
}
// questa procedura stampa a video le due matrici date in ingresso ed il loro prodotto
void moltiplica_matrici(int r1, int c1, int r2, int c2, int m1[][5], int m2[][5])
{
	/*da Wikipedia:In matematica, e più precisamente in algebra lineare, la moltiplicazione di matrici è il prodotto righe per colonne tra due matrici, 
	possibile sotto certe condizioni, che dà luogo ad un'altra matrice. Se una matrice rappresenta una applicazione lineare, 
	il prodotto fra matrici è la traduzione della composizione di due applicazioni lineari. Quindi se due matrici 2 x 2 rappresentano ad esempio due rotazioni 
	nel piano di angoli a e ß, il loro prodotto è definito in modo tale da rappresentare una rotazione di angolo a + ß */
int c[c2];
int y=0;
int a=0;
int b=0;
int d=0;
int m3[r1][c2];
	for (int i=0;i<r1;i++)
	{
		for (int j=0;j<c2;j++)
		{
			while (y<c1) //y deve essere minore del numero di colonne della prima matrice
			{
			c[y]=(m1[i][b]*m2[a][j]); // prodotto righe per colonne
			b++;a++;
			y++;
			}
			b=0;a=0;
			for (int g=0;g<c1;g++) d+=c[g];
			m3[i][j]=d;// mette il valore nella matrice 
			y=0;
			d=0;
		}
	}
cout << "la prima matrice: " << endl;
for (int i=0;i<r1;i++)
{
	for (int j=0;j<c1;j++)
	{
	cout << m1[i][j] << " ";	
	}
cout << endl;
}
cout << "la seconda matrice: " << endl;
for (int i=0;i<r2;i++)
{
	for (int j=0;j<c2;j++)
	{
	cout << m2[i][j] << " ";	
	}
cout << endl;
}
cout << "il prodotto tra matrici: " << endl;
for (int i=0;i<r1;i++)
{
	for (int j=0;j<c2;j++)
	{
	cout << m3[i][j] << " ";	
	}
cout << endl;
}

}

int main()
{
	char r;
	int righe1,righe2,colonne1,colonne2;
	int r10,c10;
	int rt,ct;
do
{

	cout << "Se vuoi valutare se una matrice e'\n"
"Triangolare alta, bassa, Diagonale o Identica premi: c\n"
"Se vuoi stampare la matrice Trasposta premi: s\n"
"Se vuoi fare il prodotto tra due matrici premi: r\n"
"Se vuoi uscire dal Menu' premi: u\n" ;
cin >> r;
switch (r){
case 'c':{
	leggi_righe_colonne(r10,c10);
	int m10[r10][5];
	leggi_matrice(r10,c10,m10);
	valuta_matrice(r10,c10,m10);
}break;
case 's':{
	leggi_righe_colonne(rt,ct);
	int mtrasp[rt][5];
	leggi_matrice(rt,ct,mtrasp);
	trasposta(rt,ct,mtrasp);
}break;
	case 'r':{
		leggi_righe_colonne(righe1,colonne1);
		leggi_righe_colonne(righe2,colonne2);
		if(righe1!=colonne2)
		{
			cout << "Il numero delle righe della prima matrice deve essere uguale a quello delle colonne della seconda matrice per poter fare il prodotto" << endl;
			cout << "reinserisci la seconda matrice" << endl;
			leggi_righe_colonne(righe2, colonne2);
		}
		int matrice2[righe2][5];
		int matrice1[righe1][5];
		leggi_matrice(righe1,colonne1,matrice1);
		leggi_matrice(righe2,colonne2,matrice2);
		moltiplica_matrici(righe1,colonne1,righe2,colonne2,matrice1,matrice2);
	}break;
case 'u':{}break;
default : cout << "carattere non consentito" << endl;
}
}
while (r!='u');
}
