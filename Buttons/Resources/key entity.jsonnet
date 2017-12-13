local common = import "common.jsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "index"]) {
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
