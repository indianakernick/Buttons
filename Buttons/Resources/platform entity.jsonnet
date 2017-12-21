local common = import "common.jsonnet";

function(params) {
  components: common.checkParams(params, ["pos", "size"]) {
    StaticSpriteRendering: {
      sprite: "platform"
    },
    Transform: {},
    PhysicsBody: common.getPosSize(params) + {
      body: "platform body.json"
    }
  }
}
