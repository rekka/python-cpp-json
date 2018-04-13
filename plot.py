import matplotlib.pyplot as plt
import numpy as np
from hypot import hypot

bs = np.linspace(0., 5., 10)
rs = [hypot(dict(a = 2., b = b)) for b in bs]

plt.plot([r["c"] for r in rs])
plt.show()
