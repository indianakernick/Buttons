local common = import "common.jsonnet";

function(params) {
  components: {
    Activation: {
      active: true
    },
    Collision: {},
    KeyRendering: {},
    Transform: {},
    PhysicsBody: common.getPos(params) + {
      body: "sensor body.json"
    },
    Key: {
      index: params.index
    }
  }
}
