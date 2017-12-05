local common = import "common.jsonnet";

function(params) {
  components: {
    BoxRendering: {},
    Transform: {},
    PhysicsBody: common.getPosSize(params) + {
      body: "box body.json"
    }
  }
}
