# 2. Character manipulation \<char.h\>

Character manipulation library is contained in a single header, <char.h>, and provides macros for using control characters by their short names (`ACK`), for checking the set of a chacater (letter, digit, symbol, etc), converting characters from one set to another (from lowercase to uppercase).

Below is the table of ASCII character set. 

- Characters belonging to the Control Character Set are inside blue cells (x00&mdash;x1F and x7F);
- Characters belonging to the Symbol Character Set are inside yellow cells (x20&mdash;x2F and x3A&mdash;x40 and x5B&mdash;x60 and x7B&mdash;x7E);
- Characters belonging to the Digit Character Set are inside pink/magenta cells (x30&mdash;x39);
- Characters belonging to the Uppercase Character Set are inside red cells (x41&mdash;x5A);
- Characters belonging to the Lowercase Character Set are inside green cells (x61&mdash;x7A);
- Characters belonging to the Whitespace Character Set are in red color (x09&mdash;x0D);
- The Letter Character Set is a combined set of the Uppercase Character Set and the Lowercase Character Set;
- The Alphaneumeric Character Set is a combined set of the Letter Character Set and the Digit Character Set;
- The Extended ASCII Character Set is any character beyond the order number 127 (x7F) or ␡ character.

<table id="ASCII">
  <thead>
    <tr>
      <th></th>
      <th>00</th>
      <th>01</th>
      <th>02</th>
      <th>03</th>
      <th>04</th>
      <th>05</th>
      <th>06</th>
      <th>07</th>
      <th>08</th>
      <th>09</th>
      <th>0A</th>
      <th>0B</th>
      <th>0C</th>
      <th>0D</th>
      <th>0E</th>
      <th>0F</th>
      <th></th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <th><b>00</b></th>
      <td class="ASCII-control">&#9216;</td>
      <td class="ASCII-control">&#9217;</td>
      <td class="ASCII-control">&#9218;</td>
      <td class="ASCII-control">&#9219;</td>
      <td class="ASCII-control">&#9220;</td>
      <td class="ASCII-control">&#9221;</td>
      <td class="ASCII-control">&#9222;</td>
      <td class="ASCII-control">&#9223;</td>
      <td class="ASCII-control">&#9224;</td>
      <td class="ASCII-control ASCII-whitespace">&#9225;</td>
      <td class="ASCII-control ASCII-whitespace">&#9226;</td>
      <td class="ASCII-control ASCII-whitespace">&#9227;</td>
      <td class="ASCII-control ASCII-whitespace">&#9228;</td>
      <td class="ASCII-control ASCII-whitespace">&#9229;</td>
      <td class="ASCII-control">&#9230;</td>
      <td class="ASCII-control">&#9231;</td>
      <th><b>0F</b></th>
    </tr>
    <tr>
      <th><b>10</b></th>
      <td class="ASCII-control">&#9232;</td>
      <td class="ASCII-control">&#9233;</td>
      <td class="ASCII-control">&#9234;</td>
      <td class="ASCII-control">&#9235;</td>
      <td class="ASCII-control">&#9236;</td>
      <td class="ASCII-control">&#9237;</td>
      <td class="ASCII-control">&#9238;</td>
      <td class="ASCII-control">&#9239;</td>
      <td class="ASCII-control">&#9240;</td>
      <td class="ASCII-control">&#9241;</td>
      <td class="ASCII-control">&#9242;</td>
      <td class="ASCII-control">&#9243;</td>
      <td class="ASCII-control">&#9244;</td>
      <td class="ASCII-control">&#9245;</td>
      <td class="ASCII-control">&#9246;</td>
      <td class="ASCII-control">&#9247;</td>
      <th><b>1F</b></th>
    </tr>
    <tr>
      <th><b>20</b></th>
      <td class="ASCII-symbol">&#9251;</td>
      <td class="ASCII-symbol">!</td>
      <td class="ASCII-symbol">&quot;</td>
      <td class="ASCII-symbol">&num;</td>
      <td class="ASCII-symbol">$</td>
      <td class="ASCII-symbol">%</td>
      <td class="ASCII-symbol">&amp;</td>
      <td class="ASCII-symbol">&#39;</td>
      <td class="ASCII-symbol">(</td>
      <td class="ASCII-symbol">)</td>
      <td class="ASCII-symbol">&ast;</td>
      <td class="ASCII-symbol">+</td>
      <td class="ASCII-symbol">,</td>
      <td class="ASCII-symbol">-</td>
      <td class="ASCII-symbol">.</td>
      <td class="ASCII-symbol">/</td>
      <th><b>2F</b></th>
    </tr>
    <tr>
      <th><b>30</b></th>
      <td class="ASCII-digit">0</td>
      <td class="ASCII-digit">1</td>
      <td class="ASCII-digit">2</td>
      <td class="ASCII-digit">3</td>
      <td class="ASCII-digit">4</td>
      <td class="ASCII-digit">5</td>
      <td class="ASCII-digit">6</td>
      <td class="ASCII-digit">7</td>
      <td class="ASCII-digit">8</td>
      <td class="ASCII-digit">9</td>
      <td class="ASCII-symbol">:</td>
      <td class="ASCII-symbol">;</td>
      <td class="ASCII-symbol">&lt;</td>
      <td class="ASCII-symbol">=</td>
      <td class="ASCII-symbol">&gt;</td>
      <td class="ASCII-symbol">?</td>
      <th><b>3F</b></th>
    </tr>
    <tr>
      <th><b>40</b></th>
      <td class="ASCII-symbol">@</td>
      <td class="ASCII-uppercase">A</td>
      <td class="ASCII-uppercase">B</td>
      <td class="ASCII-uppercase">C</td>
      <td class="ASCII-uppercase">D</td>
      <td class="ASCII-uppercase">E</td>
      <td class="ASCII-uppercase">F</td>
      <td class="ASCII-uppercase">G</td>
      <td class="ASCII-uppercase">H</td>
      <td class="ASCII-uppercase">I</td>
      <td class="ASCII-uppercase">J</td>
      <td class="ASCII-uppercase">K</td>
      <td class="ASCII-uppercase">L</td>
      <td class="ASCII-uppercase">M</td>
      <td class="ASCII-uppercase">N</td>
      <td class="ASCII-uppercase">O</td>
      <th><b>4F</b></th>
    </tr>
    <tr>
      <th><b>50</b></th>
      <td class="ASCII-uppercase">P</td>
      <td class="ASCII-uppercase">Q</td>
      <td class="ASCII-uppercase">R</td>
      <td class="ASCII-uppercase">S</td>
      <td class="ASCII-uppercase">T</td>
      <td class="ASCII-uppercase">U</td>
      <td class="ASCII-uppercase">V</td>
      <td class="ASCII-uppercase">W</td>
      <td class="ASCII-uppercase">X</td>
      <td class="ASCII-uppercase">Y</td>
      <td class="ASCII-uppercase">Z</td>
      <td class="ASCII-symbol">[</td>
      <td class="ASCII-symbol">\</td>
      <td class="ASCII-symbol">]</td>
      <td class="ASCII-symbol">^</td>
      <td class="ASCII-symbol">_</td>
      <th><b>5F</b></th>
    </tr>
    <tr>
      <th><b>60</b></th>
      <td class="ASCII-symbol">&grave;</td>
      <td class="ASCII-lowercase">a</td>
      <td class="ASCII-lowercase">b</td>
      <td class="ASCII-lowercase">c</td>
      <td class="ASCII-lowercase">d</td>
      <td class="ASCII-lowercase">e</td>
      <td class="ASCII-lowercase">f</td>
      <td class="ASCII-lowercase">g</td>
      <td class="ASCII-lowercase">h</td>
      <td class="ASCII-lowercase">i</td>
      <td class="ASCII-lowercase">j</td>
      <td class="ASCII-lowercase">k</td>
      <td class="ASCII-lowercase">l</td>
      <td class="ASCII-lowercase">m</td>
      <td class="ASCII-lowercase">n</td>
      <td class="ASCII-lowercase">o</td>
      <th><b>6F</b></th>
    </tr>
    <tr>
      <th><b>70</b></th>
      <td class="ASCII-lowercase">p</td>
      <td class="ASCII-lowercase">q</td>
      <td class="ASCII-lowercase">r</td>
      <td class="ASCII-lowercase">s</td>
      <td class="ASCII-lowercase">t</td>
      <td class="ASCII-lowercase">u</td>
      <td class="ASCII-lowercase">v</td>
      <td class="ASCII-lowercase">w</td>
      <td class="ASCII-lowercase">x</td>
      <td class="ASCII-lowercase">y</td>
      <td class="ASCII-lowercase">z</td>
      <td class="ASCII-symbol">{</td>
      <td class="ASCII-symbol">&vert;</td>
      <td class="ASCII-symbol">}</td>
      <td class="ASCII-symbol">~</td>
      <td class="ASCII-control">␡</td>
      <th><b>7F</b></th>
    </tr>
  </tbody>
  <thead>
    <tr>
      <th></th>
      <th>F0</th>
      <th>F1</th>
      <th>F2</th>
      <th>F3</th>
      <th>F4</th>
      <th>F5</th>
      <th>F6</th>
      <th>F7</th>
      <th>F8</th>
      <th>F9</th>
      <th>FA</th>
      <th>FB</th>
      <th>FC</th>
      <th>FD</th>
      <th>FE</th>
      <th>FF</th>
      <th></th>
    </tr>
  </thead>
</table>

<table>
  <thead>
    <tr>
      <th colspan="2">Legend</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="background-color:#EEF"></td>
      <td>Control characters</td>
    </tr>
    <tr>
      <td style="background-color:#FFE"></td>
      <td>Symbol characters</td>
    </tr>
    <tr>
      <td style="background-color:#FEF"></td>
      <td>Digit characters</td>
    </tr>
    <tr>
      <td style="background-color:#FEE"></td>
      <td>Uppercase letter characters</td>
    </tr>
    <tr>
      <td style="background-color:#EFE"></td>
      <td>Lowercase letter characters</td>
    </tr>
    <tr>
      <td style="color:#800">A</td>
      <td>Whitespaces</td>
    </tr>
  </tbody>
</table>
