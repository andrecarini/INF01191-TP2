# INF01191 - 2º Trabalho Prático

[Servidor LSE: informações do hardware](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Servidor%20LSE%20informac%CC%A7o%CC%83es%20do%20hardware%209712bbcfe58f408398ea77d41508e841.md)

[Contadores disponíveis](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Contadores%20disponi%CC%81veis%2000442ac36fde4bb4a139bb9c2ceb1f19.md)

---

Contadores interessantes:

- PAPI_L1_DCM  Level 1 data cache misses
- PAPI_L2_DCM  Level 2 data cache misses

---

O que vamos testar: como que a localidade dos dados na memória afetam os cache misses.

O código a ser testado: multiplicação de matrizes.

Duas variantes:

1. Multiplicação normal de matrizes. A x B.
2. Vamos transpor B e então modificar o código de multiplicação para o resultado continuar exato. Ou seja, o acesso à memória de B vai ser diferente. Será que vai ser melhor ou pior?

---

[Código completo em C](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Co%CC%81digo%20completo%20em%20C%2037a31296276a449db5bec982ab425565.md)

- Lembrete: como funciona multiplicação de matrizes? (Variante 1)
    
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%201.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%202.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%203.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%204.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%205.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%206.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%207.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%208.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%209.png)
    
- Linguagem C usa ******************row-major****************** layout para matrizes.
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2010.png)
    
- Como é o layout em memória de uma matriz?
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2011.png)
    
- Como é o layout em memória da matriz transposta?
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2012.png)
    
- E como fazemos a multiplicação gerar o mesmo resultado mas com a matriz B transposta? (Variante 2)
    
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2013.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2014.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2015.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2016.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2017.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2018.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2019.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2020.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2021.png)
    
    ![Untitled](INF01191%20-%202%C2%BA%20Trabalho%20Pra%CC%81tico%20f58fb2cb75a14f21a2233f214e634d9c/Untitled%2022.png)
    

---

```bash
g++ -std=c++11 matrix.cpp papito.cpp -I$PWD/../papi/install/include -L$PWD/../papi/install/lib $PWD/../papi/install/lib/libpapi.a -o matrix.o -lpapi
```

---

Resultados:

- Variante normal
    
    ```bash
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1609861718      102394178       15685303
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1529051331      102810286       15677052
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1620028946      102860172       15686493
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    2049652148      100017972       16885003
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1664277332      102783447       15731390
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1685522815      102384775       15692741
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1619781275      102885861       15688678
    ```
    
- Variante com transposição
    
    ```bash
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1151501841      15677939        548853
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1152130636      15678616        546491
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1153207113      15678246        553957
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1151700094      15674458        544843
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1152174638      15680131        545781
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1154451119      15694097        567671
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1152140502      15675553        545784
    
    aluno@lse:~/Documents/PAPIto$ ./matrix.o
    TOT_CYC L1_DCM  L2_DCM
    1151542202      15675519        542727
    ```
    

As duas variantes calculam exatamente a mesma matriz C. Mas a variante 2 tem apenas 10% dos cache misses em L1 da variante 1! Como B é  transposta, as colunas viram linhas e o acesso passa a ser sequencial.
