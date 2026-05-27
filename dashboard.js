// --- NEXCORE Dashboard UI Logic ---

const randomRange = (min, max) => (Math.random() * (max - min) + min).toFixed(1);

setInterval(() => {
    // Simulate real-time CPU and RAM updates
    const cpu = randomRange(30, 95);
    const ram = randomRange(40, 88);

    const cpuVal = document.getElementById('cpu-val');
    const ramVal = document.getElementById('ram-val');

    if (cpuVal) cpuVal.innerText = `${Math.round(cpu)}%`;
    if (ramVal) ramVal.innerText = `${Math.round(ram)}%`;

}, 2000);

// Cyber Defense Terminal Simulator
const terminalLogs = [
    "[AI_BRAIN] Isolation Forest anomaly_score=0.01",
    "[SCALER] CPU < 20%, triggering scale_in()",
    "[DEFENSE] IP 192.168.1.104 passed signature check.",
    "API_GATEWAY: Authorized JWT access."
];

const terminal = document.getElementById('terminal');
if (terminal) {
    setInterval(() => {
        const logText = terminalLogs[Math.floor(Math.random() * terminalLogs.length)];
        const timestamp = new Date().toISOString().split('T')[1].slice(0,12);
        
        const newLog = document.createElement('div');
        newLog.innerHTML = `<span style="color: #666;">[${timestamp}]</span> ${logText}`;
        
        terminal.appendChild(newLog);
        if (terminal.childElementCount > 10) terminal.removeChild(terminal.firstChild);
        terminal.scrollTop = terminal.scrollHeight;
    }, 1500);
}