#include <stdio.h> 
#include <ctype.h>

int main() {
	FILE *archivo;
	char c;
	int palindromo = 0;
	char texto [20000];
	int i = 0;
	int palabra = 0;
	char palindromolargo [20000];


	archivo = fopen("archivolab.txt", "r");
	if (archivo == NULL) {
		printf ("No es posible abrir el archivo.\n");
		return 1;
	} 

	while (( c = fgetc(archivo)) != EOF) {
		if (isalpha(c)) {
			if (isupper(c)) {
				c = tolower(c);
			} 
			texto[i++] = c;
		} 
	}
	fclose(archivo);

		for (int d = 0; d < i; d++) {
			for(int r = i - 1; r >= d; r--){
				int contador = 1;
				for (int j = d, k = r; j < k; j++, k--) {
					if( texto[j] != texto[k]){
					contador = 0;
					break;
					}
				}	
					if (contador){
						if (r - d + 1 > palindromo) {
							palabra = d;
							palindromo = r - d + 1;
						}	
					}
			}
		
			for (int j = 0; j < palindromo; j ++) {
				palindromolargo[j] = texto[palabra + j];
			}
			palindromolargo[palindromo] = '\0';
		}

	printf("El polindromo mas largo es: %s\n", palindromolargo);
	return 0;
}	
