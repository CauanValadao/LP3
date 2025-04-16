package Prova1;

public class LP3Prova1E5 {
    public static void main(String[] args){
        Lampada vet[] = new Lampada[10];

        for(Contador cont = new Contador(); cont.menorQue(vet.length); cont.incrementa())
            vet[cont.getContador()] = new Lampada();
        
        System.out.printf("Lampadas criadas: \n\n");	

        for(Contador cont = new Contador(); cont.menorQue(vet.length); cont.incrementa())
            System.out.printf("%f\n", vet[cont.getContador()].getIntensidade());

        for(Contador cont = new Contador(); cont.menorQue(vet.length); cont.incrementa())
            vet[cont.getContador()].setIntensidade((cont.getContador() + 1.0f)/10.0f);
        
        System.out.printf("\nAumentando a intensidade das lampadas: \n\n");

        for(Contador cont = new Contador(); cont.menorQue(vet.length); cont.incrementa())
            System.out.printf("%f\n", vet[cont.getContador()].getIntensidade());
    }
}
