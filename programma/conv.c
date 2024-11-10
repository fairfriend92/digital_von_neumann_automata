#include <stdio.h>

#define MAXLEN 100

int main ()
{
  int lato, i, j, k, n, iter;
  char griglia[MAXLEN][MAXLEN][MAXLEN], c;
  float x = 0.0/0.0; 
  FILE *fp, *fpout, *fpscript, *fpgif, *fptest;

  printf("inserire il lato della griglia\n");
  scanf("%d", &lato);
  printf("\ninserire il numero di iterazioni\n");
  scanf("%d", &iter);
  fp = fopen("timing.txt", "r");
  fpout = fopen("out.txt", "w");
  fpscript = fopen("script.p", "w");
  fpgif = fopen("gif.p", "w");
  fptest = fopen("test.txt", "w");
  //while((c = getc(fp)) != EOF)
  //printf("%c", c);

  /* popola la griglia con gli stati degli automi */
  for(k=0; k<iter; k++)
    for(i=0; i<lato; i++)
      for(j=0; j<lato; j++)
	{
	  c=getc(fp);
	  if(c=='0' || c=='1')
	    griglia[i][j][k]=c;
	  else j--;
	}
  /* scrive un file di testo formattandolo per gnuplot */

  /* scrive lo script per la creazione del file gif */
  fprintf(fpgif, "reset\nset term gif animate\nset terminal gif animate delay 50\nset output \"animation.gif\"\nn=%d\ni=0\nload \"script.p\"\nset output\n", iter);

  /* scrive lo script per gnuplot nel file */
  fprintf(fpscript, "set key off\nset size ratio -1\nset xrange [-1:11]\nset yrange[-1:11]\n");
  fprintf(fpscript, "plot ");
  for(k = 0; k < lato; k++)
    if(k != lato-1)
      fprintf(fpscript, "\"out.txt\" index i using 1:%d pt 5 ps 5.5, ", k+2);
    else fprintf(fpscript, "\"out.txt\" index i using 1:%d pt 5 ps 5.5\n", k+2);
  fprintf(fpscript, "replot\npause 1\ni=i+1\nif(i<n) reread\n");

  /* scrive la prima riga della tabella */
  fprintf(fpout, "#X ");
  for(k = 0; k < lato; k++)
    fprintf(fpout, "Y%d ", k);
  fprintf(fpout, "\n");

  /* scrive la tabella per ogni iterazione */  
  for(k = 0; k < iter; k++)
    {
      for(i = 0; i < lato; i++)
	{
	  fprintf(fpout, "%-5d", i);
	  for(j = 0; j < lato; j++)
	    if(griglia[i][j][k] == '1')
	      fprintf(fpout, "%-5d", j);
	    else fprintf(fpout, "%-5.0f", x);
	  fprintf(fpout, "\n");
	}
      fprintf(fpout, "\n\n");
    }
}
