+++
question = "Como rodar código em C++?"
date = 2019-02-17T19:22:35-03:00
weight = 20
draft = false
+++

Todo código feito para C++ usa a versão C++14. Para compilar execute o seguinte comando:

{{< highlight bash >}}
  g++ -std=c++14 <INPUT_FILE_NAME> -o <OUTPUT_FILE_NAME>
{{< /highlight >}}

E para rodar o código e verificar os resultados:

{{< highlight bash >}}
  ./<OUTPUT_FILE_NAME>
{{< /highlight >}}
