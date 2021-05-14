#include <stdio.h>


int tiempo(int,int);

int main(int argc, char const *argv[])
{
	int pesoMax,kilometros,numVehiculos,tiempototal=0,menor;
	printf("Ingrese pesoMax kilometros numVehiculos\n");
	scanf("%d%d%d",&pesoMax,&kilometros,&numVehiculos);
	int pesoVeh[numVehiculos];
	int velCar[numVehiculos];
	for (int i = 0; i < numVehiculos; ++i)
	{
		printf("peso-velocidad: ");
		scanf("%d%*[-]%d",&pesoVeh[i],&velCar[i]);
		printf("\n");
	}
	int contPeso=0;
	int sumPesoCar=0;
	for (int i = 0; i < numVehiculos; ++i)
	{
		sumPesoCar=sumPesoCar+pesoVeh[i];
		if (sumPesoCar+pesoVeh[i+1]>pesoMax)
		{
			menor=velCar[i];
			for (int j = 1; j < i; ++j)
			{
				if (menor<velCar[j])
					menor=velCar[j];
				printf("%d",menor);
			}

			tiempototal= tiempototal+ tiempo(kilometros,menor);
			sumPesoCar=0;
			

		}
	}

	

	return 0;
}

int tiempo(int kilometros,int s){
	int segundos;
	segundos=(kilometros/s)*60;
	printf("%d\n",segundos );
	return segundos;

}