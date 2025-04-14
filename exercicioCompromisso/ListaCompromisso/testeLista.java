package exercicioCompromisso.ListaCompromisso;
import exercicioData.*;

public class testeLista {
    public static void main(String[] args){
        ListaCompromissoOrdenada lista = new ListaCompromissoOrdenada(4);

        Data data = new Data(23,4,2008), data2 = new Data(23,4,2006);
        Data data3 = new Data(23,4,2009);
        Data data4 = new Data(12, 9, 2020);
        Data data5 = new Data(24, 2, 2010);
        Data data6 = new Data(6, 10, 2009);

        lista.adicionaCompromisso(data);
        lista.adicionaCompromisso(data2);
        lista.adicionaCompromisso(data3);

        lista.desmarcaCompromisso(data);

        lista.adicionaCompromisso(data4);
        lista.adicionaCompromisso(data5);
        lista.adicionaCompromisso(data6);

        lista.listaCompromisso();
        

    }
}
