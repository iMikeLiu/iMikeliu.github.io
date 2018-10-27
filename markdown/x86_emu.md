<script src="/script/libv86.js"></script>
<p>
<a>RAM大小</a>
<textarea id="RAM" style="width:auto;height:autu">256</textarea><a>MBit</a>
</p>
<p>
<a>显存大小</a>
<textarea id="VGA_RAM" style="width:auto;height:autu">16</textarea><a>MBit</a>
</p>
<script>
"use strict"
</script>
<button onClick='
    var emulator = window.emulator = new V86Starter({
        memory_size: document.getElementById("RAM").innerHTML*1024*1024,
        vga_memory_size: document.getElementById("VGA_RAM").innerHTML*1024*1024,
        screen_container: document.getElementById("screen_container"),
        bios: {
            url: "../bios/seabios.bin",
        },
        vga_bios: {
            url: "../bios/vgabios.bin",
        },
        fda: {
            url: "../pic/freedos722.img",
        },
        autostart: true,
    });'>run</button>
<div id="screen_container">
    <div style="white-space: pre; font: 14px monospace; line-height: 14px;{text-align:center;"></div>
    <canvas style="display: none"></canvas>
</div>
