package exercicioListaCompromisso;
import exercicioData.*;

public class testeLista {
    public static void main(String[] args){
        ListaCompromissoDesordenada lista = new ListaCompromissoDesordenada(10);

        Data data = new Data(23,4,2008), data2 = new Data(23,4,2006);
        Data data3 = new Data(23,4,2009);

        lista.adicionaCompromisso(data);
        lista.adicionaCompromisso(data2);
        lista.adicionaCompromisso(data3);

        lista.desmarcaCompromisso(data);

        lista.listaCompromisso();
        

    }
}
