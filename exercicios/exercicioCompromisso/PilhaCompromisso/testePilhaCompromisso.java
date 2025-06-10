package exercicioCompromisso.PilhaCompromisso;
import exercicioData.*;

public class testePilhaCompromisso {
    public static void main(String[] args){
        PilhaCompromisso lista = new PilhaCompromisso(4);

    Data data = new Data(23,4,2008), data2 = new Data(23,4,2006);
    Data data3 = new Data(23,4,2009);
    Data data4 = new Data(12, 9, 2020);
    Data data5 = new Data(24, 2, 2010);
    //Data data6 = new Data(6, 10, 2009);
   // /Data data7 = new Data(23, 4, 2015);

    lista.adicionaCompromisso(data);
    lista.adicionaCompromisso(data2);
    lista.adicionaCompromisso(data3);
    lista.adicionaCompromisso(data4);

    lista.listaCompromisso();
    System.out.printf("\n\n");
    lista.adicionaCompromisso(data5);

    lista.desmarcaCompromisso();
    lista.desmarcaCompromisso();

    lista.listaCompromisso();
    System.out.printf("\n\n");

   Data.mostraData(data3);

    lista.listaCompromisso();
    }
}
