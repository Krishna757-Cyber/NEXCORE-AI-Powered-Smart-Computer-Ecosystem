// --- NEXCORE 3D Hologram Engine (Three.js) ---
const container = document.getElementById('canvas-container');
if (container && typeof THREE !== 'undefined') {
    const scene = new THREE.Scene();
    const camera = new THREE.PerspectiveCamera(45, window.innerWidth / window.innerHeight, 0.1, 1000);
    camera.position.z = 5;

    const renderer = new THREE.WebGLRenderer({ alpha: true, antialias: true });
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.setPixelRatio(window.devicePixelRatio);
    container.appendChild(renderer.domElement);

    const hologramGroup = new THREE.Group();
    scene.add(hologramGroup);

    // Core Sphere
    const coreGeometry = new THREE.IcosahedronGeometry(1.5, 4);
    const coreMaterial = new THREE.MeshPhongMaterial({
        color: 0x02050A, emissive: 0x002233,
        transparent: true, opacity: 0.9, flatShading: true
    });
    const coreMesh = new THREE.Mesh(coreGeometry, coreMaterial);
    hologramGroup.add(coreMesh);

    // Wireframe
    const wireGeometry = new THREE.IcosahedronGeometry(1.52, 2);
    const wireMaterial = new THREE.MeshBasicMaterial({
        color: 0x00F5FF, wireframe: true,
        transparent: true, opacity: 0.2, blending: THREE.AdditiveBlending
    });
    const wireMesh = new THREE.Mesh(wireGeometry, wireMaterial);
    hologramGroup.add(wireMesh);

    // Lighting
    scene.add(new THREE.AmbientLight(0xffffff, 0.2));
    const pointLight = new THREE.PointLight(0x00F5FF, 2, 10);
    pointLight.position.set(2, 2, 2);
    scene.add(pointLight);

    function animate() {
        requestAnimationFrame(animate);
        coreMesh.rotation.y += 0.002;
        wireMesh.rotation.y += 0.003;
        wireMesh.rotation.x += 0.001;
        renderer.render(scene, camera);
    }
    
    window.addEventListener('resize', () => {
        camera.aspect = window.innerWidth / window.innerHeight;
        camera.updateProjectionMatrix();
        renderer.setSize(window.innerWidth, window.innerHeight);
    });

    animate();
}