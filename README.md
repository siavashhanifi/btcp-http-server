<h1>btcp-http-server</h1>
<p> A multithreaded(one per client) HTTP server using the <code>Windows Sockets 2 library</code> with blocking TCP sends and recieves. </p>
<h2>Build & Run</h2>
<p>First the requirements are listed then the build instruction.</p>
<h3>Requirements</h3>
<p>The requirements are listed below:</p>
<ul>
  <li><code>ws2_32.lib</code> - static library for Windows Sockets 2.</li>
  <li><code>cxx_std_17</code> - compiler with c++17 support.</li>
</ul>
<h3> Build </h3>
<ol>
  <li>Use CMake to configure and generate build environment.</li>
  <li>Build the program in your environment!</li>
</ol>
<h3> Run </h3>
<ol>
  <li>Place website files in <code>/www</code></li>
  <li>run <code>btcp-http-server.exe port</code></li>
</ol>
